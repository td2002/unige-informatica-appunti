package lab07;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CSVProcessorUnsorted implements CSVProcessor {

	protected void merge(Readable readable, Map<Person, Integer> map) {
		try (var sc = new Scanner(readable)) {
			sc.useDelimiter("\\s*,\\s*|\\s*\\n\\s*");
			while (sc.hasNext()) {
		        Person p = new Person(sc.next().toUpperCase(), sc.next().toUpperCase(), Long.parseLong(sc.next()));
		        int val = Integer.parseInt(sc.next());
		        if (map.get(p) == null) {
		        	map.put(p, val);
		        } else {
		        	map.replace(p, map.get(p)+val);
		        }
		        if (sc.hasNextLine())
				sc.nextLine(); // skips the remaining columns, if any
			}
		}
	}

	@Override
	public Map<Person, Integer> merge(Readable readable) {
		var map = new HashMap<Person, Integer>();
		merge(readable, map);
		return map;
	}

}
