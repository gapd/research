package lio;

import java.awt.Color;
import java.awt.Point;
import java.util.Hashtable;
import cons.Cons;
import cons.Loop;
import cons.Symbol;

/**
 * ペン(位置・色・太さ)を表現する。
 */
public class Pen extends Object
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
	 * リスト(二進木)からペンを作るコンストラクタ。
	 */
	public Pen(Cons aList)
	{
		this();
		this.fromList(aList);
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
	 * リスト(二進木)から自分のフィールドを設定する。
	 */
	public Hashtable<Symbol, Object> fromList(Cons aList)
	{
		// 名前(シンボル)のチェック。
		Class aClass = this.getClass();
		Symbol name = Symbol.of(aClass.getName());
		Symbol head = (Symbol)(aList.car());
		if (name != head) { return null; }
		
		// 属性テーブル(フィールド表)を作る。
		Cons tail = (Cons)(aList.cdr());
		Hashtable<Symbol, Object> table = new Hashtable<Symbol, Object>();
		for (Object each : tail.loop()) 
		{
			Cons cell = (Cons)each;
			Symbol key = (Symbol)(cell.car());
			Object value = (Object)(cell.cdr());
			table.put(key, value);
		}
		
		// 位置を設定する。
		Cons list = (Cons)(table.get(Symbol.of("position")));
		Hashtable<Symbol, Object> xy = new Hashtable<Symbol, Object>();
		for (Object each : list.loop()) 
		{
			Cons cell = (Cons)each;
			Symbol key = (Symbol)(cell.car());
			Object value = (Object)(cell.cdr());
			xy.put(key, value);
		}
		int x = (Integer)(xy.get(Symbol.of("x")));
		int y = (Integer)(xy.get(Symbol.of("y")));
		position = new Point(x, y);

		// 色を設定する。
		list = (Cons)(table.get(Symbol.of("color")));
		Hashtable<Symbol, Object> rgb = new Hashtable<Symbol, Object>();
		for (Object each : list.loop()) 
		{
			Cons cell = (Cons)each;
			Symbol key = (Symbol)(cell.car());
			Object value = (Object)(cell.cdr());
			rgb.put(key, value);
		}
		int r = (Integer)(rgb.get(Symbol.of("r")));
		int g = (Integer)(rgb.get(Symbol.of("g")));
		int b = (Integer)(rgb.get(Symbol.of("b")));
		color = new Color(r, g, b);

		// 太さを設定する。
		nib = (Integer)(table.get(Symbol.of("nib")));
		
		return table;
	}

	/**
	 * 自分をリストに変換して応答する。
	 */
	public Cons toList()
	{
		Class aClass = this.getClass();
		Cons aList = new Cons(Symbol.of(aClass.getName()), Cons.nil);

		// 位置を二進木する。
		Cons pList = new Cons(Symbol.of("position"), Cons.nil);
		Cons aPair = new Cons(Symbol.of("x"), position.x);
		pList = pList.add(aPair);
		aPair = new Cons(Symbol.of("y"), position.y);
		pList = pList.add(aPair);
		aList = aList.add(pList);
		
		// 色を二進木する。
		pList = new Cons(Symbol.of("color"), Cons.nil);
		aPair = new Cons(Symbol.of("r"), color.getRed());
		pList = pList.add(aPair);
		aPair = new Cons(Symbol.of("g"), color.getGreen());
		pList = pList.add(aPair);
		aPair = new Cons(Symbol.of("b"), color.getBlue());
		pList = pList.add(aPair);
		aList = aList.add(pList);
		
		// 太さを二進木する。
		aPair = new Cons(Symbol.of("nib"), nib);
		aList = aList.add(aPair);

		return aList;
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
