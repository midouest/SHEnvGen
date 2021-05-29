#pragma once

#include "SC_PlugIn.hpp"

namespace SHEnvGen
{
    class SHEnvGen : public SCUnit
    {
    public:
        SHEnvGen();

    private:
        void next(int nSamples);

        enum State
        {
            Idle,
            Rise,
            Fall,
        };

        double amp = 0.0;
        State state = Idle;
    };

} // namespace SHEnvGen
