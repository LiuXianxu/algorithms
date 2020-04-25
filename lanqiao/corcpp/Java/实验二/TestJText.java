package Exercise6;

import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class TestJText
{
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("JTextField and JTextArea");
		JTextField textField = new JTextField("");
		JTextArea textArea = new JTextArea("||");
		JPanel panel = new JPanel();
		frame.setSize(400, 400);
		textField.setPreferredSize(new Dimension(100,30));
		textArea.setPreferredSize(new Dimension(300,30));
		panel.add(textField);
		panel.add(textArea);
		frame.add(panel);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

}
