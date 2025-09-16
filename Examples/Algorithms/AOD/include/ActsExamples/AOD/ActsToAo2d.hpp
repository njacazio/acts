// ActsToAo2d.hpp
#include <Acts/Definitions/Algebra.hpp>
#include <Acts/Surfaces/Surface.hpp>
#include <ActsExamples/EventData/Track.hpp>
#include <ActsExamples/Framework/AlgorithmContext.hpp>
#include <ActsExamples/Framework/DataHandle.hpp>  // Add this include
#include <ActsExamples/Framework/IAlgorithm.hpp>

#include <cmath>

#include <ReconstructionDataFormats/Track.h>

// Wrap to (-pi, pi]
inline double wrapPi(double a) {
  while (a <= -M_PI)
    a += 2 * M_PI;
  while (a > M_PI)
    a -= 2 * M_PI;
  return a;
}

// 1) Alpha from an ACTS plane surface (normal's xy angle)
inline double alphaFromPlane(const Acts::GeometryContext& gctx,
                             const Acts::Surface& surf) {
  // For plane surfaces, col(2) is the normal (z of the local frame).
  Acts::Vector3 n = surf.transform(gctx).rotation().col(2);
  return wrapPi(std::atan2(n.y(), n.x()));
}

// 2) Alpha from a global position (radial frame)
inline double alphaFromPosition(double x, double y) {
  return wrapPi(std::atan2(y, x));
}

// 3) (Optional) Snap to ALICE TPC sector centers (18 per side => 20°)
inline double snapAlphaToTPC(double alpha) {
  constexpr double d = 20.0 * M_PI / 180.0;           // 20 degrees in rad
  int k = static_cast<int>(std::llround(alpha / d));  // nearest sector
  return wrapPi(k * d);
}

// 4) Enforce ALICE cos(phi_local) > 0 convention by flipping phi_local if
// needed
inline double enforceAlicePhiLocal(double phiLocal) {
  double c = std::cos(phiLocal);
  if (c < 0.0)
    return wrapPi(phiLocal + M_PI);
  return phiLocal;
}

#include <string>

namespace ActsExamples {

class TrackParCov {
 public:
  // ALICE track parametrization: [Y, Z, Snp, Tgl, 1/pt, X, Cov[15]]
  float y;        // Y position
  float z;        // Z position
  float snp;      // sin(phi)
  float tgl;      // tan(lambda)
  float qOverPt;  // 1/pt
  float x;        // X position
  float cov[15];  // Covariance matrix elements (packed as per ALICE convention)

  TrackParCov() : y(0), z(0), snp(0), tgl(0), qOverPt(0), x(0) {
    std::fill(std::begin(cov), std::end(cov), 0.0f);
  }

  template <typename TrkType>
  TrackParCov(
      const TrkType& btp,
      double alpha = 0,  // ALICE sector angle you want to express the state in
      double lengthScaleInv = 1.0  // e.g. 0.1 for mm->cm
  ) {
    const auto& pars = btp.parameters();

    // Read back local plane coords (assumed plane aligned as in
    // makeAliceLikePlane)
    y = pars[Acts::eBoundLoc0] * lengthScaleInv;
    z = pars[Acts::eBoundLoc1] * lengthScaleInv;

    const double phi = pars[Acts::eBoundPhi];
    const double theta = pars[Acts::eBoundTheta];
    const double qOverP = pars[Acts::eBoundQOverP];

    // Convert angles to ALICE conventions
    const double phiLocal = wrapPi(phi - alpha);
    const double snp_d = std::sin(phiLocal);
    const double cpl = std::cos(phiLocal);
    // Enforce ALICE convention cos(phi_local)>0 (flip by ±pi if needed)
    double phiLocalFixed = phiLocal;
    double snpFixed = snp_d;
    if (cpl < 0) {
      phiLocalFixed = wrapPi(phiLocal + M_PI);
      snpFixed = std::sin(phiLocalFixed);
    }

    snp = snpFixed;
    tgl = std::cos(theta) / std::sin(theta);  // = cot(theta) = pz/pt

    // q/pt from q/p
    qOverPt = qOverP * std::sqrt(1.0 + tgl * tgl);

    // Plane position: we assume the ACTS surface is the ALICE x=const plane
    // created with makeAliceLikePlane, so loc0=y, loc1=z and:
    alpha = alpha;

    // Recover x from the plane placement: for a standard plane we can take
    // x as the signed distance along its normal from the global origin to the
    // plane origin. If you built the plane with makeAliceLikePlane, that x was
    // the input "x". Here we set it to zero unless you pass it in separately or
    // compute it from the surface.
    x = 0.0;  // fill from your geometry if needed
  }
};

class ActsToAo2d final : public IAlgorithm {
 public:
  struct Config {
    std::string inputTracks = "InputTrackParameters";
  };
  struct Ao2dTrack {
    float x, y, z;
    float px, py, pz;
    // Add more fields as needed
  };
  ActsToAo2d(Config cfg, Acts::Logging::Level lvl)
      : IAlgorithm("ActsToAo2d", lvl),
        m_cfg(std::move(cfg)),
        m_inputTrackParameters(this, m_cfg.inputTracks) {}

  ~ActsToAo2d() override = default;

  ProcessCode execute(const AlgorithmContext& ctx) const override {
    const auto& tracks = m_inputTrackParameters(ctx);
    std::vector<TrackParCov> ao2dTracks;
    for (const auto& trackParams : tracks) {
      TrackParCov cov(trackParams);
      ao2dTracks.push_back(cov);
    }
    // TODO: Write out ao2dTracks to AO2D format or hand off to next step
    return ProcessCode::SUCCESS;
  }

 private:
  Config m_cfg;
  ReadDataHandle<TrackParametersContainer> m_inputTrackParameters;
};

}  // namespace ActsExamples
