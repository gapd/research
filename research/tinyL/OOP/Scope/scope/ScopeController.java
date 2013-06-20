package scope;

import java.awt.event.MouseEvent;

/**
 * マウスの周辺を映し出すスコープのコントローラ。
 */
public class ScopeController extends mvc.Controller
{
	/**
	 * 上位コンストラクタを継承するただけのコンストラクタ。
	 */
	public ScopeController()
	{
		super();
	}

	/**
	 * マウスクリックしても、なにもしないようにする。
	 */
	public void mouseClicked(MouseEvent aMouseEvent)
	{
		return;
	}

	/**
	 * マウスドラッグしても、なにもしないようにする。
	 */
	public void mouseDragged(MouseEvent aMouseEvent)
	{
		return;
	}
}
