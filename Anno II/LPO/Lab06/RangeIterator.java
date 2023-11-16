package lab06_03_16;

import java.util.Iterator;
import java.util.NoSuchElementException;

class RangeIterator implements Iterator<Integer> {

    // object fields and constructors
	private int end;
	private int cur;
	private int start;
	
	public RangeIterator (int start, int end) throws NoSuchElementException{
		if(start > end) throw new NoSuchElementException();
		this.end = end;
		this.cur = start;
		this.start = start;
	}

    @Override
    public boolean hasNext() {
    	if (this.cur + 1 <= this.end) return true;
    	this.cur = this.start;
    	return false;
    	//return (this.cur + 1 <= this.end);
    }

    @Override
    public Integer next() {
    	if(this.hasNext()) return this.cur++;
    	return null;
    }

}