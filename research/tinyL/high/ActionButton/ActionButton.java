import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ActionButton extends Frame implements ActionListener
{
    ActionButton()
    {
        super("ActionButton");
        Button aButton = new Button("Exit");
        aButton.addActionListener(this);
        this.add(aButton);
        this.setSize(200, 100);
        this.setLocation(100, 100);
        this.setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        System.exit(0);
    }

    public static void main(String[] arguments)
    {
        new ActionButton();
    }
}
