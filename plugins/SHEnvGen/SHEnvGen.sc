SHEnvGen : UGen {
    *kr { arg trig = 0.0, attack = 1.0, release = 1.0, mul = 1.0, add = 0.0;
        ^this.multiNew('control', trig, attack, release).madd(mul, add);
    }

    checkInputs {
        ^this.checkValidInputs;
    }
}
