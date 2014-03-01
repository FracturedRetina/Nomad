#pragma once
class Object {
	protected:
		bool collectable;
		bool obstacle;
		int xpos;
		int ypos;
	public:
		virtual ~Object() {}
		virtual void onContact() = 0;
		virtual void interact() = 0;
		virtual void print() = 0;
};