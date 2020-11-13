/******************************************************************************
 *
 * Copyright (c) 2013-2019, Lawrence Livermore National Security, LLC
 * and other libROM project developers. See the top-level COPYRIGHT
 * file for details.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 *
 *****************************************************************************/

// Description: The class that determines the next time at which a sample
//              should be taken for basis generation using the static SVD
//              approach.

#ifndef included_StaticSVDSampler_h
#define included_StaticSVDSampler_h

#include "SVDSampler.h"
#include "StaticSVD.h"

namespace CAROM {

/**
 * Class StaticSVDSampler knows, given a static svd implementation, the
 * time at which the next sample is needed.  It also knows given a time whether
 * it is time for the next sample.  All state vectors are sampled in the
 * static SVD implementation so it is always time for a new sample.
 */
class StaticSVDSampler : public SVDSampler
{
public:
    /**
     * @brief Constructor.
     *
     * @param[in] options The struct containing the options for this basis
     *                    generator.
     */
    StaticSVDSampler(
        StaticSVDOptions options);

    /**
     * @brief Destructor.
     */
    ~StaticSVDSampler();

    /**
     * @brief Returns true if it is time for the next sample.
     *
     * As the static algorithm samples everything this always returns true.
     *
     * @param[in] time Time of interest--unused.
     *
     * @return true
     */
    virtual
    bool
    isNextSample(
        double time);

    /**
     * @brief Computes next time a state sample is needed.
     *
     * @param[in] u_in The state at the specified time--unused.
     * @param[in] rhs_in The right hand side at the specified time--unused.
     * @param[in] time The simulation time for the state.
     *
     * @return The current simulation time as the static algorithm samples at
     * each time step.
     */
    virtual
    double
    computeNextSampleTime(
        double* u_in,
        double* rhs_in,
        double time);

    /**
     * @brief Resets sample time step.
     *
     * @param[in] new_dt New value of sample time step.
     */
    virtual
    void
    resetDt(
        double new_dt);

private:
    /**
     * @brief Unimplemented default constructor.
     */
    StaticSVDSampler();

    /**
     * @brief Unimplemented copy constructor.
     */
    StaticSVDSampler(
        const StaticSVDSampler& other);

    /**
     * @brief Unimplemented assignment operator.
     */
    StaticSVDSampler&
    operator = (
        const StaticSVDSampler& rhs);
};

}

#endif
