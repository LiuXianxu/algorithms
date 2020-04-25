package Exercise6;

import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class TestJPanel {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		JPanel panel = new JPanel();
		JButton buttion = new JButton("Button");
		JLabel label = new JLabel("This is a LABEL");
		panel.setBackground(Color.RED);
		panel.add(buttion);
		panel.add(label);
		frame.add(panel);
		frame.setSize(400,400);
		frame.setVisible(true);
	}
}
