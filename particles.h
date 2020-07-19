#include "particle.h"


namespace particle {

	const Particle explosion = {{
		{{
			"   ",
			" X ",
			"   "
		}},
		{{
			" X ",
			"X X",
			" X "
		}},
		{{
			"X X",
			" X ",
			"X X"
		}},
		{{
			" X",
			"X X",
			" X "
		}},
		{{
			"   ",
			" X ",
			"   "
		}},
	}, {3, 3}, 1};


	const Particle big_explosion = {{
		{{
			"         ",
			"    X    ",
			"   X     ",
			"         ",
			"         "
		}},
		{{
			"         ",
			"    X  X ",
			"   X     ",
			"    X    ",
			"         "
		}},
		{{
			"  X   X  ",
			"    X    ",
			"  XX   X ",
			" X  X    ",
			"      X  "
		}},
		{{
			"  X   X  ",
			" X  X    ",
			"  XXX X  ",
			" X  X    ",
			"      X  "
		}},
		{{
			"      X  ",
			" X  X    ",
			"   XX  X ",
			" X  X    ",
			"         "
		}},
		{{
			"       X",
			" X      ",
			"   XX   ",
			"    X   ",
			"       X"
		}},
		{{
			"     X  ",
			"        ",
			"   X    ",
			"    X   ",
			"        "
		}}
	}, {9, 5}, 1};

}