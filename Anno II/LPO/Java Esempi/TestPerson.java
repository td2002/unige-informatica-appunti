
public class TestPerson {

	public static void main(String[] args) {
		
		Person davide = new Person("Davide", "Trioli");
		Person edoardo = new Person("Edoardo", "Mafodda");
		Person mattia = new Person("Mattia", "Toscano");
		
		System.out.println(davide);
		System.out.println(edoardo);
		System.out.println(mattia);
		
		System.out.println("- - - - - - - - - - - - - - - - - - - -");
		
		Person.join(davide, mattia);
		Person.join(mattia, edoardo);
		
		System.out.println(davide);
		System.out.println(edoardo);
		System.out.println(mattia);
		
		System.out.println("- - - - - - - - - - - - - - - - - - - -");
		
		Person.divorce(davide, mattia);
		
		System.out.println(davide);
		System.out.println(edoardo);
		System.out.println(mattia);
		
		System.out.println("- - - - - - - - - - - - - - - - - - - -");
		
		Person.divorce(davide, mattia);
		
		System.out.println(davide);
		System.out.println(edoardo);
		System.out.println(mattia);

	}

}
