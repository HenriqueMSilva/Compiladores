class fluxControl3 {

    public static int main(String[] args) {
		int k; k = 0;
		int i,g; i = 0; g = 0;
		int is_pair; is_pair = 0;
		int input;
		input = 40;
        while( k < 5){
			if(k == 1) { 
				input = input - 2;
				i = 0;
				g = 0;
				while(i < 100){
					while(g < 50){
						input = input + 2;
						if((g % 2) == 0){
							is_pair = is_pair + 1;
						} 
						g = g + 1;							
					}
					g = 0;
					i = i + 1;
				}
			}
			else {
				if( k == 2) {input = input *3;}
			}
			k = k + 1;
		}
		System.out.print("Is pair: ");
		System.out.print(is_pair);
		System.out.print("|\n");
    }
}