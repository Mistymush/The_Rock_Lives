//
// Bullet.h
//

#include "EventCollision.h"
#include "Object.h"

#define BULLET_CHAR '-'

namespace df{

	class Bullet : public Object {

	private:
		void out();
		void hit(const EventCollision *p_c);

	public:
		Bullet(Position hero_pos);
		int eventHandler(const Event *p_e);
		void draw();
	};

}
