package lab07;

import java.util.Map;

public interface CSVProcessor {

	Map<Person, Integer> merge(Readable readable);

	default Map<Person, Integer> mergeAndSort(Readable readable) {
		throw new UnsupportedOperationException();
	}
}