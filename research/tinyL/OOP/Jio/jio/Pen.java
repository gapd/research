package jio;

import java.awt.Color;
import java.awt.Point;
import java.io.Serializable;

/**
 * ペン(位置・色・太さ)を表現する。
 */
public class Pen extends Object implements Serializable
{
	/**
	 * ペンの位置を表すフィールド。
	 */
	private Point position;

	/**
	 * ペンの色を保持するフィールド。
	 */
	private Color color;
	
	/**
	 * ペンの太さを保持するフィールド。
	 */
	private int nib;
	
	/**
	 * ペンを作るコンストラクタ。
	 */
	public Pen()
	{
		super();
		position = new Point(0, 0);
		color = Color.black;
		nib = 1;
	}

	/**
	 * ペンの位置を応答する。
	 */
	public Point position()
	{
		return position;
	}
	
	/**
	 * ペンの位置を設定する。
	 */
	public void position(int x, int y)
	{
		position = new Point(x, y);
		return;
	}
	
	/**
	 * ペンの色を応答する。
	 */
	public Color color()
	{
		return color;
	}
	
	/**
	 * ペンの色を設定する。
	 */
	public void color(Color c)
	{
		color = c;
		return;
	}	
	
	/**
	 * ペンの太さを応答する。
	 */
	public int nib()
	{
		return nib;
	}
	
	/**
	 * ペンの太さを設定する。
	 */
	public void nib(int n)
	{
		nib = n;
		return;
	}

	/**
	 * 自分を文字列に変換して応答する。
	 */
	public String toString()
	{
		StringBuffer aBuffer = new StringBuffer();
		Class aClass = this.getClass();
		aBuffer.append(aClass.getName());
		aBuffer.append("[position=");
		aBuffer.append(position);
		aBuffer.append(",color=");
		aBuffer.append(color);
		aBuffer.append(",nib=");
		aBuffer.append(nib);
		aBuffer.append("]");
		return aBuffer.toString();
	}
}
