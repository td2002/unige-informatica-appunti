package timers;

public class StoppableTimerClass extends TimerClass implements StoppableTimer {

	private boolean stopped;

	public StoppableTimerClass() {
	}

        public StoppableTimerClass(StoppableTimer other) { // costruttore di copia
	        super(other);
	        this.stopped = other.stopped();
	}

	public boolean stopped() {
		return this.stopped;
	}

	public void stop() {
		this.stopped = true;
	}

	public void restart() {
		this.stopped = false;
	}

	@Override
	public boolean isRunning() {
		return super.isRunning() && !this.stopped();
	}

	@Override
	public int reset(int minutes) {
		this.restart();
		return super.reset(minutes);
	}

	public static void main(String[] args) {
		StoppableTimer t1 = new StoppableTimerClass();
		t1.stop();
		StoppableTimer t2 = new StoppableTimerClass(t1);
		assert t1.getTime() == t2.getTime() && t1.stopped() == t2.stopped();
	}
}
