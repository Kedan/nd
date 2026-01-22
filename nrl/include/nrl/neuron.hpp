#pragma once

namespace nd::nrl {
	
	class Activator {
		
	};

	class Neuron {
		public:
			void input(float t_i) { m_input = t_i; }
			void setWeight(float w) { m_weight = w; }
			void setBias(float b) { m_bias = b; }
		public:
			// activation functions
			float hardlim(float input)	{ return input < 0.f ? 0.f : 1.f; }
			float purelin(float input)	{ return input*m_weight + m_bias; }
		public:
			float operator()(float input) {	return hardlim(purelin(input)); }
		protected:
			float m_weight{1};
			float m_bias{0};
	}; // template class Neuron
	 
}; // namespace nd::nrl
