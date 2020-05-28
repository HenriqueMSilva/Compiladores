/*class CeD{
	public static void main(String[] args){
		System.out.print("Teste\tde \fstring\\\"\r%%");
   }
}
*/


class CeD{




	public static int a;
	public static void main(String[] args){
		double dd;
		/*
		//a =  Integer.parseInt(args[1+0-4 + 7]) + 5;
		//System.out.print( a );
		System.out.print("\n");

		System.out.print( Integer.parseInt(args[1]) );
		System.out.print("\n");
    	*/
    	
    	//a = 4;
    	//dd = 4.0 ;
		
		//ddble(ddble());
		dd = 4.0;
		ddble(dd);
		a = ddble(6);
		
		ddble( Integer.parseInt(args[1]) );
		ddble( args.length );
		
		//System.out.print( dd );
		//System.out.print( "\n" );

		System.out.print( a + 14_9 );
		System.out.print( "\n" );

    }


	public static int ddble(  ){
		System.out.print("we\n");
	    return 1; 
	}


	public static void ddble( double e ){
		//int dd;
		//dd = 4;
		System.out.print("wDoubleEe\n");
		//da erro, corrigir e preciso
		System.out.print( e - 5);
		//System.out.print(e);
		System.out.print("\n");
	    return ; 
	}


	public static int ddble( int e ){
		System.out.print("Inte\n");
		System.out.print(e + 4);
		System.out.print("\n");

	    return e + 5; 
	}


}