#include "plugin.hpp"
#include <math.h>
#include "dsp/filter.hpp"
#include <cstdio>

struct Big_Marko : Module {
	enum ParamId {
		_1_TO_1_PROBABILITY_PARAM,
		_1_TO_2_PROBABILITY_PARAM,
		_1_TO_3_PROBABILITY_PARAM,
		_1_TO_4_PROBABILITY_PARAM,
		_1_TO_5_PROBABILITY_PARAM,
		_1_TO_6_PROBABILITY_PARAM,
		_1_TO_7_PROBABILITY_PARAM,
		_1_TO_8_PROBABILITY_PARAM,
		_2_TO_1_PROBABILITY_PARAM,
		_2_TO_2_PROBABILITY_PARAM,
		_2_TO_3_PROBABILITY_PARAM,
		_2_TO_4_PROBABILITY_PARAM,
		_2_TO_5_PROBABILITY_PARAM,
		_2_TO_6_PROBABILITY_PARAM,
		_2_TO_7_PROBABILITY_PARAM,
		_2_TO_8_PROBABILITY_PARAM,
		_3_TO_1_PROBABILITY_PARAM,
		_3_TO_2_PROBABILITY_PARAM,
		_3_TO_3_PROBABILITY_PARAM,
		_3_TO_4_PROBABILITY_PARAM,
		_3_TO_5_PROBABILITY_PARAM,
		_3_TO_6_PROBABILITY_PARAM,
		_3_TO_7_PROBABILITY_PARAM,
		_3_TO_8_PROBABILITY_PARAM,
		_4_TO_1_PROBABILITY_PARAM,
		_4_TO_2_PROBABILITY_PARAM,
		_4_TO_3_PROBABILITY_PARAM,
		_4_TO_4_PROBABILITY_PARAM,
		_4_TO_5_PROBABILITY_PARAM,
		_4_TO_6_PROBABILITY_PARAM,
		_4_TO_7_PROBABILITY_PARAM,
		_4_TO_8_PROBABILITY_PARAM,
		_5_TO_1_PROBABILITY_PARAM,
		_5_TO_2_PROBABILITY_PARAM,
		_5_TO_3_PROBABILITY_PARAM,
		_5_TO_4_PROBABILITY_PARAM,
		_5_TO_5_PROBABILITY_PARAM,
		_5_TO_6_PROBABILITY_PARAM,
		_5_TO_7_PROBABILITY_PARAM,
		_5_TO_8_PROBABILITY_PARAM,
		_6_TO_1_PROBABILITY_PARAM,
		_6_TO_2_PROBABILITY_PARAM,
		_6_TO_3_PROBABILITY_PARAM,
		_6_TO_4_PROBABILITY_PARAM,
		_6_TO_5_PROBABILITY_PARAM,
		_6_TO_6_PROBABILITY_PARAM,
		_6_TO_7_PROBABILITY_PARAM,
		_6_TO_8_PROBABILITY_PARAM,
		_7_TO_1_PROBABILITY_PARAM,
		_7_TO_2_PROBABILITY_PARAM,
		_7_TO_3_PROBABILITY_PARAM,
		_7_TO_4_PROBABILITY_PARAM,
		_7_TO_5_PROBABILITY_PARAM,
		_7_TO_6_PROBABILITY_PARAM,
		_7_TO_7_PROBABILITY_PARAM,
		_7_TO_8_PROBABILITY_PARAM,
		_8_TO_1_PROBABILITY_PARAM,
		_8_TO_2_PROBABILITY_PARAM,
		_8_TO_3_PROBABILITY_PARAM,
		_8_TO_4_PROBABILITY_PARAM,
		_8_TO_5_PROBABILITY_PARAM,
		_8_TO_6_PROBABILITY_PARAM,
		_8_TO_7_PROBABILITY_PARAM,
		_8_TO_8_PROBABLILITY_PARAM,
		STATE_1_LEVEL_PARAM,
		STATE_2_LEVEL_PARAM,
		STATE_3_LEVEL_PARAM,
		STATE_4_LEVEL_PARAM,
		STATE_5_LEVEL_PARAM,
		STATE_6_LEVEL_PARAM,
		STATE_7_LEVEL_PARAM,
		STATE_8_LEVEL_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		_1_TO_1_PROBABILITY_INPUT,
		_1_TO_2_PROBABILITY_INPUT,
		_1_TO_3_PROBABILITY_INPUT,
		_1_TO_4_PROBABILITY_INPUT,
		_1_TO_5_PROBABILITY_INPUT,
		_1_TO_6_PROBABILITY_INPUT,
		_1_TO_7_PROBABILITY_INPUT,
		_1_TO_8_PROBABILITY_INPUT,
		_2_TO_1_PROBABILITY_INPUT,
		_2_TO_2_PROBABILITY_INPUT,
		_2_TO_3_PROBABILITY_INPUT,
		_2_TO_4_PROBABILITY_INPUT,
		_2_TO_5_PROBABILITY_INPUT,
		_2_TO_6_PROBABILITY_INPUT,
		_2_TO_7_PROBABILITY_INPUT,
		_2_TO_8_PROBABILITY_INPUT,
		_3_TO_1_PROBABILITY_INPUT,
		_3_TO_2_PROBABILITY_INPUT,
		_3_TO_3_PROBABILITY_INPUT,
		_3_TO_4_PROBABILITY_INPUT,
		_3_TO_5_PROBABILITY_INPUT,
		_3_TO_6_PROBABILITY_INPUT,
		_3_TO_7_PROBABILITY_INPUT,
		_3_TO_8_PROBABILITY_INPUT,
		_4_TO_1_PROBABILITY_INPUT,
		_4_TO_2_PROBABILITY_INPUT,
		_4_TO_3_PROBABILITY_INPUT,
		_4_TO_4_PROBABILITY_INPUT,
		_4_TO_5_PROBABILITY_INPUT,
		_4_TO_6_PROBABILITY_INPUT,
		_4_TO_7_PROBABILITY_INPUT,
		_4_TO_8_PROBABILITY_INPUT,
		_5_TO_1_PROBABILITY_INPUT,
		_5_TO_2_PROBABILITY_INPUT,
		_5_TO_3_PROBABILITY_INPUT,
		_5_TO_4_PROBABILITY_INPUT,
		_5_TO_5_PROBABILITY_INPUT,
		_5_TO_6_PROBABILITY_INPUT,
		_5_TO_7_PROBABILITY_INPUT,
		_5_TO_8_PROBABILITY_INPUT,
		_6_TO_1_PROBABILITY_INPUT,
		_6_TO_2_PROBABILITY_INPUT,
		_6_TO_3_PROBABILITY_INPUT,
		_6_TO_4_PROBABILITY_INPUT,
		_6_TO_5_PROBABILITY_INPUT,
		_6_TO_6_PROBABILITY_INPUT,
		_6_TO_7_PROABABILITY_INPUT,
		_6_TO_8_PROBABILITY_INPUT,
		_7_TO_1_PROBABILITY_INPUT,
		_7_TO_2_PROBABILITY_INPUT,
		_7_TO_3_PROBABILITY_INPUT,
		_7_TO_4_PROBABILITY_INPUT,
		_7_TO_5_PROBABILITY_INPUT,
		_7_TO_6_PROBABILITY_INPUT,
		_7_TO_7_PROBABILITY_INPUT,
		_7_TO_8_PROBABILITY_INPUT,
		_8_TO_1_PROBABILITY_INPUT,
		_8_TO_2_PROBABILITY_INPUT,
		_8_TO_3_PROBABILITY_INPUT,
		_8_TO_4_PROBABILITY_INPUT,
		_8_TO_5_PROBABILITY_INPUT,
		_8_TO_6_PROABABILITY_INPUT,
		_8_TO_7_PROBABILITY_INPUT,
		_8_TO_8_PROBABILITY_INPUT,
		STATE_1_LEVEL_INPUT,
		STATE_2_LEVEL_INPUT,
		STATE_3_LEVEL_INPUT,
		STATE_4_LEVEL_INPUT,
		STATE_5_LEVEL_INPUT,
		STATE_6_LEVEL_INPUT,
		STATE_7_LEVEL_INPUT,
		STATE_8_LEVEL_INPUT,
		CLOCK_INPUT,
		RESET_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		OUTPUT_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		STATE_1_ACTIVE_LIGHT,
		STATE_2_ACTIVE_LIGHT,
		STATE_3_ACTIVE_LIGHT,
		STATE_4_ACTIVE_LIGHT,
		STATE_5_ACTIVE_LIGHT,
		STATE_6_ACTIVE_LIGHT,
		STATE_7_ACTIVE_LIGHT,
		STATE_8_ACTIVE_LIGHT,
		LIGHTS_LEN
	};

	Big_Marko() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(_1_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_1_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_1_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_1_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_1_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_1_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_1_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_1_TO_8_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_1_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configParam(_2_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_2_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_2_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_2_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_2_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_2_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_2_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_2_TO_8_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_2_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configParam(_3_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_3_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_3_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_3_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_3_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_3_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_3_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_3_TO_8_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_3_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configParam(_4_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_4_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_4_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_4_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_4_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_4_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_4_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_4_TO_8_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_4_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configParam(_5_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_5_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_5_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_5_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_5_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_5_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_5_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_5_TO_8_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_5_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configParam(_6_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_6_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_6_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_6_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_6_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_6_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_6_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_6_TO_8_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_6_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configParam(_7_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_7_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_7_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_7_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_7_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_7_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_7_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_7_TO_8_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_7_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configParam(_8_TO_1_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_8_TO_2_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_8_TO_3_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_8_TO_4_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_8_TO_5_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_8_TO_6_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_8_TO_7_PROBABILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(_8_TO_8_PROBABLILITY_PARAM, 0.f, 10.f, 5.f, "");
		configParam(STATE_8_LEVEL_PARAM, -5.f, 5.f, 0.f, "");
		configInput(CLOCK_INPUT, "");
		configInput(STATE_1_LEVEL_INPUT, "");
		configInput(_1_TO_1_PROBABILITY_INPUT, "");
		configInput(_1_TO_2_PROBABILITY_INPUT, "");
		configInput(_1_TO_3_PROBABILITY_INPUT, "");
		configInput(_1_TO_4_PROBABILITY_INPUT, "");
		configInput(_1_TO_5_PROBABILITY_INPUT, "");
		configInput(_1_TO_6_PROBABILITY_INPUT, "");
		configInput(_1_TO_7_PROBABILITY_INPUT, "");
		configInput(_1_TO_8_PROBABILITY_INPUT, "");
		configInput(RESET_INPUT, "");
		configInput(STATE_2_LEVEL_INPUT, "");
		configInput(_2_TO_1_PROBABILITY_INPUT, "");
		configInput(_2_TO_2_PROBABILITY_INPUT, "");
		configInput(_2_TO_3_PROBABILITY_INPUT, "");
		configInput(_2_TO_4_PROBABILITY_INPUT, "");
		configInput(_2_TO_5_PROBABILITY_INPUT, "");
		configInput(_2_TO_6_PROBABILITY_INPUT, "");
		configInput(_2_TO_7_PROBABILITY_INPUT, "");
		configInput(_2_TO_8_PROBABILITY_INPUT, "");
		configInput(STATE_3_LEVEL_INPUT, "");
		configInput(_3_TO_1_PROBABILITY_INPUT, "");
		configInput(_3_TO_2_PROBABILITY_INPUT, "");
		configInput(_3_TO_3_PROBABILITY_INPUT, "");
		configInput(_3_TO_4_PROBABILITY_INPUT, "");
		configInput(_3_TO_5_PROBABILITY_INPUT, "");
		configInput(_3_TO_6_PROBABILITY_INPUT, "");
		configInput(_3_TO_7_PROBABILITY_INPUT, "");
		configInput(_3_TO_8_PROBABILITY_INPUT, "");
		configInput(STATE_4_LEVEL_INPUT, "");
		configInput(_4_TO_1_PROBABILITY_INPUT, "");
		configInput(_4_TO_2_PROBABILITY_INPUT, "");
		configInput(_4_TO_3_PROBABILITY_INPUT, "");
		configInput(_4_TO_4_PROBABILITY_INPUT, "");
		configInput(_4_TO_5_PROBABILITY_INPUT, "");
		configInput(_4_TO_6_PROBABILITY_INPUT, "");
		configInput(_4_TO_7_PROBABILITY_INPUT, "");
		configInput(_4_TO_8_PROBABILITY_INPUT, "");
		configInput(STATE_5_LEVEL_INPUT, "");
		configInput(_5_TO_1_PROBABILITY_INPUT, "");
		configInput(_5_TO_2_PROBABILITY_INPUT, "");
		configInput(_5_TO_3_PROBABILITY_INPUT, "");
		configInput(_5_TO_4_PROBABILITY_INPUT, "");
		configInput(_5_TO_5_PROBABILITY_INPUT, "");
		configInput(_5_TO_6_PROBABILITY_INPUT, "");
		configInput(_5_TO_7_PROBABILITY_INPUT, "");
		configInput(_5_TO_8_PROBABILITY_INPUT, "");
		configInput(STATE_6_LEVEL_INPUT, "");
		configInput(_6_TO_1_PROBABILITY_INPUT, "");
		configInput(_6_TO_2_PROBABILITY_INPUT, "");
		configInput(_6_TO_3_PROBABILITY_INPUT, "");
		configInput(_6_TO_4_PROBABILITY_INPUT, "");
		configInput(_6_TO_5_PROBABILITY_INPUT, "");
		configInput(_6_TO_6_PROBABILITY_INPUT, "");
		configInput(_6_TO_7_PROABABILITY_INPUT, "");
		configInput(_6_TO_8_PROBABILITY_INPUT, "");
		configInput(STATE_7_LEVEL_INPUT, "");
		configInput(_7_TO_1_PROBABILITY_INPUT, "");
		configInput(_7_TO_2_PROBABILITY_INPUT, "");
		configInput(_7_TO_3_PROBABILITY_INPUT, "");
		configInput(_7_TO_4_PROBABILITY_INPUT, "");
		configInput(_7_TO_5_PROBABILITY_INPUT, "");
		configInput(_7_TO_6_PROBABILITY_INPUT, "");
		configInput(_7_TO_7_PROBABILITY_INPUT, "");
		configInput(_7_TO_8_PROBABILITY_INPUT, "");
		configInput(STATE_8_LEVEL_INPUT, "");
		configInput(_8_TO_1_PROBABILITY_INPUT, "");
		configInput(_8_TO_2_PROBABILITY_INPUT, "");
		configInput(_8_TO_3_PROBABILITY_INPUT, "");
		configInput(_8_TO_4_PROBABILITY_INPUT, "");
		configInput(_8_TO_5_PROBABILITY_INPUT, "");
		configInput(_8_TO_6_PROABABILITY_INPUT, "");
		configInput(_8_TO_7_PROBABILITY_INPUT, "");
		configInput(_8_TO_8_PROBABILITY_INPUT, "");
		configOutput(OUTPUT_OUTPUT, "");
	}

	uint8_t state = 0;
	dsp::SchmittTrigger clockSchmitt, resetSchmitt;
	// we need to recalculate on every sample anyway to capture input, so we may as well be lazy and only calc/store the relevant row
	float probabilities[8];

	void process(const ProcessArgs& args) override {
		if (clockSchmitt.process(inputs[CLOCK_INPUT].getVoltage(), 0.1f, 1.f)) {
			INFO("clock pulse detected");
			advance_state();
		}
		if (resetSchmitt.process(inputs[RESET_INPUT].getVoltage(), 0.1f, 1.f)) {
			INFO("reset detected");
			reset();
		}
		update_outputs();
	}

	void update_outputs(){
		if (inputs[STATE_1_LEVEL_INPUT+state].isConnected()){
			outputs[OUTPUT_OUTPUT].setVoltage(
				inputs[STATE_1_LEVEL_INPUT+state].getVoltage()
			);
		}else{
			outputs[OUTPUT_OUTPUT].setVoltage(
				params[STATE_1_LEVEL_PARAM+state].getValue()
			);
		}

		for (int i=0; i<LIGHTS_LEN; i++){
			lights[i].setBrightness(i==state ? 1.f : 0.f);
		}
	}

	void advance_state(){
		INFO("advance_state called");
		update_probs();
		state=get_next_state();
		return;
	}
	void reset(){
		state=0;
		return;
	}

	//update the state based on the current probs (expects probs to be normalised and stacked)
	uint8_t get_next_state(){
		INFO("Getting next state");
		float rando=random::uniform();
		for (int i=0; i<7; i++){
			if (probabilities[i]>rando){
				return i;
			}
		}
		return 7;
	}

	//pull in the probs for the relevant row and then normalise the probs
	void update_probs(){
		INFO("updating probs");
		int offset=state*8;
		float total=0;
		float new_prob;
		for (int i=0; i<8; i++){
			new_prob=fmaxf(
				0., 
				inputs[offset+i].getVoltage()+params[offset+i].getValue()
			);

			probabilities[i]=new_prob;
			total+=new_prob;
		}

		INFO("read in probs as %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f", probabilities[0], probabilities[1], probabilities[2], probabilities[3], probabilities[4], probabilities[5], probabilities[6], probabilities[7]);

		//probs are stacked so that we can just rng and find the first state whose prob is greater than some random
		probabilities[0]=probabilities[0]/total;
		for (int i=1; i<8; i++){
			probabilities[i]=(probabilities[i]/total)+probabilities[i-1];
		}
		INFO("stacking probs to %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f", probabilities[0], probabilities[1], probabilities[2], probabilities[3], probabilities[4], probabilities[5], probabilities[6], probabilities[7]);
	}
};



struct Big_MarkoWidget : ModuleWidget {
	Big_MarkoWidget(Big_Marko* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/big_marko.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 16.0)), module, Big_Marko::_1_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 16.0)), module, Big_Marko::_1_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 16.0)), module, Big_Marko::_1_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 16.0)), module, Big_Marko::_1_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 16.0)), module, Big_Marko::_1_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 16.0)), module, Big_Marko::_1_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 16.0)), module, Big_Marko::_1_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 16.0)), module, Big_Marko::_1_TO_8_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(166.3, 18.0)), module, Big_Marko::STATE_1_LEVEL_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 30.53)), module, Big_Marko::_2_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 30.53)), module, Big_Marko::_2_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 30.53)), module, Big_Marko::_2_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 30.53)), module, Big_Marko::_2_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 30.53)), module, Big_Marko::_2_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 30.53)), module, Big_Marko::_2_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 30.53)), module, Big_Marko::_2_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 30.53)), module, Big_Marko::_2_TO_8_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(166.3, 32.53)), module, Big_Marko::STATE_2_LEVEL_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 45.06)), module, Big_Marko::_3_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 45.06)), module, Big_Marko::_3_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 45.06)), module, Big_Marko::_3_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 45.06)), module, Big_Marko::_3_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 45.06)), module, Big_Marko::_3_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 45.06)), module, Big_Marko::_3_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 45.06)), module, Big_Marko::_3_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 45.06)), module, Big_Marko::_3_TO_8_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(166.3, 47.06)), module, Big_Marko::STATE_3_LEVEL_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 59.59)), module, Big_Marko::_4_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 59.59)), module, Big_Marko::_4_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 59.59)), module, Big_Marko::_4_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 59.59)), module, Big_Marko::_4_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 59.59)), module, Big_Marko::_4_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 59.59)), module, Big_Marko::_4_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 59.59)), module, Big_Marko::_4_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 59.59)), module, Big_Marko::_4_TO_8_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(166.3, 61.59)), module, Big_Marko::STATE_4_LEVEL_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 74.12)), module, Big_Marko::_5_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 74.12)), module, Big_Marko::_5_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 74.12)), module, Big_Marko::_5_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 74.12)), module, Big_Marko::_5_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 74.12)), module, Big_Marko::_5_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 74.12)), module, Big_Marko::_5_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 74.12)), module, Big_Marko::_5_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 74.12)), module, Big_Marko::_5_TO_8_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(166.3, 76.12)), module, Big_Marko::STATE_5_LEVEL_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 88.65)), module, Big_Marko::_6_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 88.65)), module, Big_Marko::_6_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 88.65)), module, Big_Marko::_6_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 88.65)), module, Big_Marko::_6_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 88.65)), module, Big_Marko::_6_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 88.65)), module, Big_Marko::_6_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 88.65)), module, Big_Marko::_6_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 88.65)), module, Big_Marko::_6_TO_8_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(166.3, 90.65)), module, Big_Marko::STATE_6_LEVEL_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 103.18)), module, Big_Marko::_7_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 103.18)), module, Big_Marko::_7_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 103.18)), module, Big_Marko::_7_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 103.18)), module, Big_Marko::_7_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 103.18)), module, Big_Marko::_7_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 103.18)), module, Big_Marko::_7_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 103.18)), module, Big_Marko::_7_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 103.18)), module, Big_Marko::_7_TO_8_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(166.3, 105.18)), module, Big_Marko::STATE_7_LEVEL_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(19.0, 117.72)), module, Big_Marko::_8_TO_1_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(36.0, 117.72)), module, Big_Marko::_8_TO_2_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(53.0, 117.72)), module, Big_Marko::_8_TO_3_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(70.0, 117.72)), module, Big_Marko::_8_TO_4_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(87.0, 117.72)), module, Big_Marko::_8_TO_5_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(104.0, 117.72)), module, Big_Marko::_8_TO_6_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(121.0, 117.72)), module, Big_Marko::_8_TO_7_PROBABILITY_PARAM));
		addParam(createParamCentered<RoundSmallBlackKnob>(mm2px(Vec(138.0, 117.72)), module, Big_Marko::_8_TO_8_PROBABLILITY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(166.3, 119.71)), module, Big_Marko::STATE_8_LEVEL_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(8.2, 6.75)), module, Big_Marko::CLOCK_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 18.0)), module, Big_Marko::STATE_1_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 20.936)), module, Big_Marko::_1_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 20.936)), module, Big_Marko::_1_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 20.936)), module, Big_Marko::_1_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 20.936)), module, Big_Marko::_1_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 20.936)), module, Big_Marko::_1_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 20.936)), module, Big_Marko::_1_TO_6_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 20.936)), module, Big_Marko::_1_TO_7_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 20.936)), module, Big_Marko::_1_TO_8_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(8.2, 32.74)), module, Big_Marko::RESET_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 32.53)), module, Big_Marko::STATE_2_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 35.466)), module, Big_Marko::_2_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 35.466)), module, Big_Marko::_2_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 35.466)), module, Big_Marko::_2_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 35.466)), module, Big_Marko::_2_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 35.466)), module, Big_Marko::_2_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 35.466)), module, Big_Marko::_2_TO_6_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 35.466)), module, Big_Marko::_2_TO_7_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 35.466)), module, Big_Marko::_2_TO_8_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 47.06)), module, Big_Marko::STATE_3_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 49.996)), module, Big_Marko::_3_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 49.996)), module, Big_Marko::_3_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 49.996)), module, Big_Marko::_3_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 49.996)), module, Big_Marko::_3_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 49.996)), module, Big_Marko::_3_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 49.996)), module, Big_Marko::_3_TO_6_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 49.996)), module, Big_Marko::_3_TO_7_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 49.996)), module, Big_Marko::_3_TO_8_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 61.59)), module, Big_Marko::STATE_4_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 64.526)), module, Big_Marko::_4_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 64.526)), module, Big_Marko::_4_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 64.526)), module, Big_Marko::_4_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 64.526)), module, Big_Marko::_4_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 64.526)), module, Big_Marko::_4_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 64.526)), module, Big_Marko::_4_TO_6_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 64.526)), module, Big_Marko::_4_TO_7_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 64.526)), module, Big_Marko::_4_TO_8_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 76.12)), module, Big_Marko::STATE_5_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 79.056)), module, Big_Marko::_5_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 79.056)), module, Big_Marko::_5_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 79.056)), module, Big_Marko::_5_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 79.056)), module, Big_Marko::_5_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 79.056)), module, Big_Marko::_5_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 79.056)), module, Big_Marko::_5_TO_6_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 79.056)), module, Big_Marko::_5_TO_7_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 79.056)), module, Big_Marko::_5_TO_8_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 90.65)), module, Big_Marko::STATE_6_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 93.586)), module, Big_Marko::_6_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 93.586)), module, Big_Marko::_6_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 93.586)), module, Big_Marko::_6_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 93.586)), module, Big_Marko::_6_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 93.586)), module, Big_Marko::_6_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 93.586)), module, Big_Marko::_6_TO_6_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 93.586)), module, Big_Marko::_6_TO_7_PROABABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 93.586)), module, Big_Marko::_6_TO_8_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 105.18)), module, Big_Marko::STATE_7_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 108.116)), module, Big_Marko::_7_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 108.116)), module, Big_Marko::_7_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 108.116)), module, Big_Marko::_7_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 108.116)), module, Big_Marko::_7_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 108.116)), module, Big_Marko::_7_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 108.116)), module, Big_Marko::_7_TO_6_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 108.116)), module, Big_Marko::_7_TO_7_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 108.116)), module, Big_Marko::_7_TO_8_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(176.3, 119.71)), module, Big_Marko::STATE_8_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.474, 122.656)), module, Big_Marko::_8_TO_1_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(42.474, 122.656)), module, Big_Marko::_8_TO_2_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(59.474, 122.656)), module, Big_Marko::_8_TO_3_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.474, 122.656)), module, Big_Marko::_8_TO_4_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.474, 122.656)), module, Big_Marko::_8_TO_5_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(110.474, 122.656)), module, Big_Marko::_8_TO_6_PROABABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(127.474, 122.656)), module, Big_Marko::_8_TO_7_PROBABILITY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(144.474, 122.656)), module, Big_Marko::_8_TO_8_PROBABILITY_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(187.25, 7.269)), module, Big_Marko::OUTPUT_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 18.0)), module, Big_Marko::STATE_1_ACTIVE_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 32.53)), module, Big_Marko::STATE_2_ACTIVE_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 47.06)), module, Big_Marko::STATE_3_ACTIVE_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 61.59)), module, Big_Marko::STATE_4_ACTIVE_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 76.12)), module, Big_Marko::STATE_5_ACTIVE_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 90.65)), module, Big_Marko::STATE_6_ACTIVE_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 105.18)), module, Big_Marko::STATE_7_ACTIVE_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(156.3, 119.71)), module, Big_Marko::STATE_8_ACTIVE_LIGHT));
	}
};






Model* modelBig_Marko = createModel<Big_Marko, Big_MarkoWidget>("Big_Marko");
