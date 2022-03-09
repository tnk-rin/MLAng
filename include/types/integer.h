#include <cmath>
#include <string>

class Integer {
	public:
		Integer(float pValue) {
			value = pValue;
		}

		Integer add(Integer n) {
			return Integer(this->value + n.value);
		}

		Integer sub(Integer n) {
			return Integer(value - n.value);
		}

		Integer mul(Integer n) {
			return Integer(value * n.value);
		}

		Integer div(Integer n) {
			return Integer(value / n.value);
		}

		Integer pow(Integer n) {
			return Integer(std::pow(value, n.value));
		}

		std::string str() {
			return std::to_string(value);
		}

	private:
		double value;
		

};
