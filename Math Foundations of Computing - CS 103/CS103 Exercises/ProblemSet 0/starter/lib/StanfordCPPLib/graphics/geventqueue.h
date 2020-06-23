/*
 * File: geventqueue.h
 * -------------------
 *
 * @author Marty Stepp
 * @version 2018/09/07
 * - added doc comments for new documentation generation
 * @version 2018/08/23
 * - renamed to geventqueue.h
 * @version 2018/07/03
 * - initial version
 */

#ifndef _geventqueue_h
#define _geventqueue_h

#include <string>
#include <QObject>
#include <QReadWriteLock>
#include "gevent.h"
#include "gtypes.h"
#include "queue.h"

class GObservable;
class GThread;
class QtGui;

/**
 * The GEventQueue is a first-in, first-out (FIFO) queue of events that occur
 * on graphical interactors.
 *
 * This queue is used by our interactor classes (GButton, GCheckBox, etc.)
 * internally.  When events occur on these widgets, we place them into a GEventQueue
 * so that they can be sent out to the various event listeners in client code.
 *
 * Most clients do not need to use GEventQueue directly.
 *
 * @private
 */
class GEventQueue : public QObject {
    Q_OBJECT

public:
    static GEventQueue* instance();
    int getEventMask() const;
    GEvent getNextEvent(int mask = ANY_EVENT);
    bool isAcceptingEvent(const GEvent& event) const;
    bool isAcceptingEvent(int type) const;
    void setEventMask(int mask);
    GEvent waitForEvent(int mask = ANY_EVENT);

signals:
    void mySignal();

private:
    Q_DISABLE_COPY(GEventQueue)

    GEventQueue();

    GThunk dequeue();
    void enqueueEvent(const GEvent& event);
    bool isEmpty() const;
    GThunk peek();
    void runOnQtGuiThreadAsync(GThunk thunk);
    void runOnQtGuiThreadSync(GThunk thunk);

    static GEventQueue* _instance;
    Queue<GThunk> _functionQueue;
    Queue<GEvent> _eventQueue;
    QReadWriteLock _eventQueueMutex;
    QReadWriteLock _functionQueueMutex;
    int _eventMask;

    friend class GObservable;
    friend class GThread;
    friend class QtGui;
};

#include "private/init.h"   // ensure that Stanford C++ lib is initialized

#endif // _geventqueue_h
