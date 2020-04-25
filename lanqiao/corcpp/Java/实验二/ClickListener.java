package Exercise6;
import java.awt.event.ActionEvent;
import  java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
public class ClickListener implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		System.out.println("Button was clicked");
	}
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		JButton button = new JButton("°´Å¥");
		JPanel panel = new JPanel();
		button.addActionListener(new ClickListener());
		panel.add(button);
		frame.add(panel);
		frame.setSize(400, 400);
		frame.setVisible(true);
	}
}
