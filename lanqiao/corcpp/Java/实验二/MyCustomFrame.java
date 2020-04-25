package Exercise6;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MyCustomFrame extends JFrame{
	private JPanel panel;
	private JButton button;
	private JLabel label;
	final int FRAME_WIDTH = 400;
	final int FRAME_HEIGHT =400;
	public MyCustomFrame()
	{
		super();
		CreateComponents();
		super.setSize(FRAME_WIDTH,FRAME_HEIGHT);
		super.add(panel);
	}
	public MyCustomFrame(String s)
	{
		super(s);
		CreateComponents();
		super.setSize(FRAME_WIDTH,FRAME_HEIGHT);
		super.add(panel);
	}
	private void CreateComponents()
	{
		panel = new JPanel();
		button = new JButton();
		label = new JLabel();
		panel.add(button);
		panel.add(label);
		
	}
	public void setJButtonText(String s)
	{
		button.setText(s);
	}
	public void setJLabelText(String s)
	{
		label.setText(s);;
	}
	
	public static void main(String[] args) {
		MyCustomFrame myCustomFrame = new MyCustomFrame();
		myCustomFrame.setJButtonText("°´Å¥");
		myCustomFrame.setJLabelText("This is a JLabel");
		myCustomFrame.setVisible(true);
	}
}
