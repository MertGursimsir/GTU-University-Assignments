import javax.swing.JFrame;

public class Main{
	public static void main(String args[]){
		//Creating game object
		PegSolitaire game = new PegSolitaire();

		//exit when frame is closed
		game.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		//setting beginning size
		game.setSize(1000, 300);
		
		//make frame visible
		game.setVisible(true);
	}
}