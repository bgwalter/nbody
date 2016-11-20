#include <X11/Xlib.h>
#include <unistd.h>

#include "Universe.h"
#include "Vector3.h"
#include "Body.h"

using namespace std;

int main(void) {


	/* S E T U P   X 1 1 */

	Display *d = XOpenDisplay(NULL);
	if (d == NULL) exit(1);

	int colorbg = BlackPixel(d, DefaultScreen(d));
	int color = WhitePixel(d, DefaultScreen(d));

	int width = 600;
	int height = 600;

	Window w = XCreateSimpleWindow(d, DefaultRootWindow(d), 0, 0, width, height,
								   0, colorbg, colorbg);

	XSelectInput(d, w, StructureNotifyMask);
	XMapWindow(d, w);
	GC gc = XCreateGC(d, w, 0, NULL);
	XSetForeground(d, gc, color);

	XEvent e;
	while (e.type != MapNotify)
		XNextEvent(d, &e);


	/* S E T U P   U N I V E R S E */

    Universe u;
    u.setTimeStep(10);

	int numBodies = 10;
	Body bodies[numBodies];

	for (int i=0; i<numBodies; i++) {
		bodies[i].setRandomPosition(width * 3/8, height * 5/8);
		bodies[i].setRandomVelocity(-0.0001, 0.0001);
		bodies[i].setRandomMass(1, 1E6);
		u.addBody(&bodies[i]);
	}

	Body center(Vector3(300, 300, 300), Vector3(), Vector3(), 1E10);
	u.addBody(&center);


	/*  M A I N   L O O P */

	while (true) {
    	u.step();
		XClearWindow(d, w);

		std::vector<Body*> b = u.getBodies();
		for (int i=0; i<u.getNumBodies(); i++) {
			//b[i]->print();
			int x = b[i]->getPosition().getx();
			int y = b[i]->getPosition().gety();
			XDrawPoint(d, w, gc, x, y);
		}

		XFlush(d);
		usleep(100);
	}
}
