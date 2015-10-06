/*
Header file which define a keyboard event
*/

#ifndef EVENT_KEYBOARD
#define EVENT_KEYBOARD

#include <SFML/graphics.hpp>
#include "Event.h"


namespace df{

		const std::string _KEYBOARD_EVENT = "df::keyboard";

		enum EventKeyboardAction {
			UNDEFINED_KEYBOARD_ACTION = -1,
			KEY_PRESSED,
			KEY_RELEASED,
			KEY_DOWN,
		};

		//Keys Dragonfly recognizers. In a special namespace for input variables
		namespace Keyboard {
			enum Key {
				UNDEFINED_KEY = -1,
				SPACE, RETURN, ESCAPE, TAB, LEFTARROW, RIGHTARROW,
				UPARROW, DOWNARROW, PAUSE, MINUS, PLUS, TILDE, PERIOD,
				COMMA, SLASH, LEFTCONTROL, RIGHTCONTROL, LEFTSHIFT,
				RIGHTSHIFT, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11,
				F12, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R,
				S, T, U, V, W, X, Y, Z, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6,
				NUM7, NUM8, NUM9, NUM0,
			};
		}//!input

		class EventKeyboard : public Event {

		private:
			//our defined set of keys
			Keyboard::Key key_val;

			//catagory of keyboard event
			EventKeyboardAction keyboard_action;

		public:
			//public constructor
			EventKeyboard();

			void setKey(df::Keyboard::Key new_key);

			//Get key from event
			Keyboard::Key getKey() const;

			//Get keyboard event action. TO be used by the InputMang
			void setKeyboardAction(EventKeyboardAction new_action);

			//Get keybaord event action
			EventKeyboardAction getKeyboardAction() const;


		};//!EventKeyboard

}//!df


#endif //!EVENT_KEYBOARD