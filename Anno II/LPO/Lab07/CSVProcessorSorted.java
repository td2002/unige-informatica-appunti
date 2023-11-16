package lab07;

import java.util.Map;
import java.util.TreeMap;

public class CSVProcessorSorted extends CSVProcessorUnsorted {

	@Override
	public Map<Person, Integer> mergeAndSort(Readable readable) {
		var map = new TreeMap<Person, Integer>(new ComparePersonBySurname());
		merge(readable, map);
		return map;
	}

}