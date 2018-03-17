#pragma once

#include "../types.h"
#include "../constants.h"

class Tool {

public:
	// BEGIN---------------------------------------------- CONSTRUCTOR ------------------------------------------------
	Tool(string_t type = UNKNOWN, string_t name = UNKNOWN, bool broken = false):
		type_(type),
		name_(name),
		broken_(broken) {
	}
	// END------------------------------------------------ CONSTRUCTOR ------------------------------------------------

	// BEGIN---------------------------------------------- SETTERS ----------------------------------------------------
	// END------------------------------------------------ SETTERS ----------------------------------------------------

	// BEGIN---------------------------------------------- GETTERS ----------------------------------------------------
	string_t type() const {
		return type_;
	}

	string_t name() const {
		return name_;
	}
	// END------------------------------------------------ GETTERS ----------------------------------------------------

	// BEGIN---------------------------------------------- METHODS ----------------------------------------------------
	void broke() {}
	// END------------------------------------------------ METHODS ----------------------------------------------------

	// BEGIN---------------------------------------------- DESTRUCTOR -------------------------------------------------
	virtual ~Tool() {}
	// END------------------------------------------------ DESTRUCTOR -------------------------------------------------

protected:
	string_t type_;

	string_t name_;

	bool broken_;
};