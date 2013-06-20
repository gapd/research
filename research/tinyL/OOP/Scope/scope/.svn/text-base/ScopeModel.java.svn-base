package scope;

import java.awt.Dimension;
import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.PointerInfo;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;

/**
 * マウスの周辺を映し出すスコープのモデル。
 */
public class ScopeModel extends mvc.Model
{
	private Dimension extent;

	/**
	 * マウスの周辺の大きさを指定してスコープモデルを作るコンストラクタ。
	 */
	public ScopeModel(Dimension aDimension)
	{
		super();
		extent = aDimension;
	}
	
	/**
	 * マウスの周辺を映し出す無限ループ処理。上位クラス（モデル）のメソッド（ノーオペレーションperform）を再定義。
	 * ロボットを用いてマウス位置を中心にしてコンストラクタで指定された大きさで画面（スクリーン）をキャプチャし、
	 * その画像をモデル（自身）のピクチャとして指定して、自分が変化したと騒いで、オブザーバ（ビュー）たちへ更新を促す。
	 * 無限ループが終了するのは、ウィンドウ（MVC）を閉じたときか、割り込み例外が発生したとき。
	 */
	public void perform()
	{
		Robot aRobot;

		try
		{
			aRobot = new Robot();
		}
		catch (Exception anException)
		{
			System.err.println(anException);
			throw new RuntimeException(anException.toString());
		}
		while (true)
		{
			PointerInfo aPointerInfo;
			Point aPoint;
			int x;
			int y;
			Rectangle aRectangle;
			BufferedImage anImage;
			
			aPointerInfo = MouseInfo.getPointerInfo();
			aPoint = aPointerInfo.getLocation();
			x = aPoint.x - (extent.width / 2);
			y = aPoint.y - (extent.height / 2);
			aPoint = new Point(x, y);
			aRectangle = new Rectangle(aPoint, extent);
			anImage = aRobot.createScreenCapture(aRectangle);
			this.picture(anImage);
			this.changed();
			try
			{
				Thread.sleep(25);
			}
			catch (InterruptedException anException)
			{
				break;
			}
		}
		return;
	}
}
