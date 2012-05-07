#pragma once

#include "Feature.h"

//! Class for extracting STAR features.
/*!
	\ingroup FeatureExtractor

	Class implementing the Star keypoint detector, a modified version of the CenSurE keypoint detector described in
	Agrawal, M. and Konolige, K. and Blas, M.R. �CenSurE: Center Surround Extremas for Realtime Feature Detection and Matching�, ECCV08, 2008.
*/
extern "C++" class __declspec(dllexport) StarFeature : public Feature
{
public:
	//! Constructor.
	/*!
		\param name Name of the current feature extraction procedure.
	*/
	StarFeature(const std::string& name);

	//! Destructor.
	~StarFeature(void);

	//! Implemented virtual method for loading algorithm specific settings from the given storage.
	/*!
		\sa Feature::LoadSettingsFromFileStorage()
	*/
	void LoadSettingsFromFileStorage(const cv::FileStorage& fileStorage);

private:
	//! Implemented virtual method for the algorithm.
	/*!
		\sa Feature::Process()
	*/
	void Process(void);

	//! Implemented virtual method for feature point detection.
	void detectImpl(void);

	cv::StarDetector* star;	//!< Wrapped OpenCV STAR object.
};
