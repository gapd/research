package scope;

import java.awt.Dimension;
import javax.swing.JFrame;

/**
 * マウスの周辺を映し出すスコープ｛モデル，ビュー，コントローラ｝の例題プログラム。
 * オブザーバ・デザインパターン（MVC: Model-View-Controller）を用いた典型的（模範的）なプログラム。
 */
public class Example extends Object
{
	/**
	 * 映し出したいマウス周辺の大きさを指定してスコープモデルを作り、
	 * その大きさでウィンドウ（MVC）をいくつか（段階状に）開き、
	 * 一番初めに開いたウィンドウをフロント（アクティブ）にした後、
	 * マウスの周辺を映し出す処理を依頼する。
	 */
	public static void main(String[] arguments)
	{
		JFrame theWindow;
		Dimension aDimension;
		ScopeModel aModel;

		theWindow = null;
		aDimension = new Dimension(220, 165);
		aModel = new ScopeModel(aDimension);
		for (int index = 0; index < 4; index++)
		{
			ScopeView aView;
			JFrame aWindow;

			aView = new ScopeView(aModel, new ScopeController(), index);
			aWindow = new JFrame("Scope" + Integer.toString(index));
			aWindow.getContentPane().add(aView);
			aWindow.setMinimumSize(aDimension);
			aWindow.setMaximumSize(aDimension);
			aWindow.setResizable(false);
			aWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			aWindow.setSize(aDimension.width, aDimension.height);
			aWindow.setLocation(30 + ((aDimension.width + 20) * index), 50 + (40 * index));
			aWindow.setVisible(true);
			if (theWindow == null) theWindow = aWindow;
		}
		if (theWindow != null) theWindow.toFront();
		aModel.perform();
		return;
	}
}
