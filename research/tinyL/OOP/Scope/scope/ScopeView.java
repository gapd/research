package scope;

import java.awt.Color;
import java.awt.Point;
import java.awt.Graphics;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;

/**
 * マウスの周辺を映し出すスコープのビュー。
 */
public class ScopeView extends mvc.View
{
	private int affineInteger;
	
	/**
	 * 指定されたモデルとコントローラと自分（ビュー）でMVCを構築するコンストラクタ。
	 * 描き方を整数値で指定する。
	 */
	public ScopeView(ScopeModel aModel, ScopeController aController, int anInteger)
	{
		super(aModel, aController);
		affineInteger = anInteger;
	}

	/**
	 * 描画を行う。
	 * affineIntegerが0の場合：そのまま描画。
	 * affineIntegerが1の場合：左右反転描画。
	 * affineIntegerが2の場合：上下反転描画。
	 * affineIntegerが3の場合：拡大描画。
	 * affineIntegerが4の場合：縮小描画。
	 * affineIntegerが上記以外の場合：そのまま描画。
	 */
	public void paintComponent(Graphics aGraphics)
	{
		int width;
		int height;
		BufferedImage picture;
		
		width = this.getWidth();
		height = this.getHeight();
		aGraphics.setColor(Color.gray);
		aGraphics.fillRect(0, 0, width, height);
		if (model != null)
		{
			picture = model.picture();
			if (picture != null)
			{
				AffineTransform aTransformation;
				AffineTransformOp anOperation;
				int x;
				int y;

				switch (affineInteger)
				{
					case 1:
						aTransformation = (new AffineTransform()).getScaleInstance(-1.0, 1.0);
						aTransformation.translate(0 - picture.getWidth(), 0);
						anOperation = new AffineTransformOp(aTransformation, null);
						picture = anOperation.filter(picture, null);
						break;
					case 2:
						aTransformation = (new AffineTransform()).getScaleInstance(1.0, -1.0);
						aTransformation.translate(0, 0 - picture.getHeight());
						anOperation = new AffineTransformOp(aTransformation, null);
						picture = anOperation.filter(picture, null);
						break;
					case 3:
						aTransformation = (new AffineTransform()).getScaleInstance(2.0, 2.0);
						anOperation = new AffineTransformOp(aTransformation, null);
						picture = anOperation.filter(picture, null);
						break;
					case 4:
						aTransformation = (new AffineTransform()).getScaleInstance(0.5, 0.5);
						anOperation = new AffineTransformOp(aTransformation, null);
						picture = anOperation.filter(picture, null);
						break;
					default:
						break;
				}
				x = (width - picture.getWidth()) / 2;
				y = (height - picture.getHeight()) / 2;
				aGraphics.drawImage(picture, x, y, null);
			}
		}
		return;
	}
	 
	/**
	 * スクロールを抑制する。スコープMVCでは必要ないため、スクロール量を常にゼロに保つ。
	 */
	public Point scrollAmount()
	{
		return (new Point(0, 0));
	}
	
	/**
	 * 相対スクロールをしないようにする。スコープMVCでは必要ないため、何もしないことにする。
	 */
	public void scrollBy(Point aPoint)
	{
		return;
	}
	
	/**
	 * 絶対スクロールをしないようにする。スコープMVCでは必要ないため、何もしないことにする。
	 */
	public void scrollTo(Point aPoint)
	{
		return;
	}	
}
