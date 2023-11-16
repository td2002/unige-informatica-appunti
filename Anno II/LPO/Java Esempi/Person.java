
public class Person {
	
	
	private String name;
	private String surname;
	private static long nextSN;//class field
	private long socialSN;
	private Person spouse;
	
	public Person(String name, String surname) throws IllegalArgumentException {
		this.name = name;
		if(!checkSurName(this.name)) throw new IllegalArgumentException();
		this.surname = surname;
		if(!checkSurName(this.surname)) throw new IllegalArgumentException();
		this.spouse = null;
		this.socialSN = Person.nextSN++;
	}
	
	private boolean checkSurName(String str) {
		return str.matches("[A-Z][a-z]+( [A-Z][a-z]+)*");
	}
	
	public String getName() {
		return name;
	}
	public String getSurname() {
		return surname;
	}
	public long getSocialSN() {
		return socialSN;
	}
	public Person getSpouse() {
		return spouse;
	}
	
	public boolean isSingle() {
		return (this.spouse == null);
	}
	
	public static void join(Person p1, Person p2) {
		if(p1.getSocialSN() != p2.getSocialSN()) {
			if(p1.isSingle() && p2.isSingle()) {
				p1.spouse = p2;
				p2.spouse = p1;
			}
		}	
	}
	
	public static void divorce(Person p1, Person p2) {
		if(!p1.isSingle() && !p2.isSingle()) {
			if(p1.getSpouse().getSocialSN() == p2.getSocialSN() && p2.getSpouse().getSocialSN() == p1.getSocialSN()) {
				p1.spouse = null;
				p2.spouse = null;
			}
		}
	}
	
	public String toString() {
		return this.isSingle()? this.getSurname() + " " + this.getName() + " [SN" + this.getSocialSN() + "]: single" : this.getSurname() + " " + this.getName() + " [SN" + this.getSocialSN() + "]: in relationship with " + this.getSpouse().getSurname() + " " + this.getSpouse().getName();
	}

}
