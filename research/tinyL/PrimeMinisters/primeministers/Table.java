package primeministers;

import java.util.ArrayList;
import java.awt.image.BufferedImage;
/**
 * 表：総理大臣の情報テーブル。
 */
public class Table extends Object
{
	/**
	 * 属性リストを記憶するフィールド。
	 */
	private Attributes attributes;
	
	/**
	 * 画像群を記憶するフィールド。
	 */
	private ArrayList<BufferedImage> images;
	
	/**
	 * サムネイル画像群を記憶するフィールド。
	 */
	private ArrayList<BufferedImage> thumbnails;
	
	/**
	 * タプル群を記憶するフィールド。
	 */
	private ArrayList<Tuple> tuples;
	
	/**
	 * テーブルのコンストラクタ。
	 */
	public Table()
	{
		super();
		this.attributes = null ;
		this.images = null;
		this.thumbnails = null;
		this.tuples = null;
		return;
	}
	
	/**
	 * タプルを追加する。
	 */
	public void add(Tuple aTuple)
	{
		this.tuples().add(aTuple);
		return;
	}
	
	/**
	 * 属性リストを応答する。
	 */
	public Attributes attributes()
	{
		return this.attributes;
	}
	
	/**
	 * 属性リストを設定する。
	 */
	public void attributes(Attributes instanceOfAttributes)
	{
		attributes = instanceOfAttributes;
	    return;	
	}
	
	/**
	 * 画像群を応答する。
	 */
	public ArrayList<BufferedImage> images()
	{
		return this.images;
	}
	
	/**
	 * サムネイル画像群を応答する。
	 */
	public ArrayList<BufferedImage> thumbnails()
	{
		return this.thumbnails;
	}
	
	/**
	 * 自分自身を文字列にして、それを応答する。
	 */
	public String toString()
	{
		StringBuffer aBuffer = new StringBuffer();
		
		aBuffer.append(this.attributes());
		aBuffer.append("\n");
		for(Tuple aTuple: this.tuples())
		{
			aBuffer.append(aTuple);
			aBuffer.append("\n");
		}
		aBuffer.deleteCharAt(aBuffer.length() - 1);
		return aBuffer.toString();
	}
	
	/**
	 * タプル群を応答する。
	 */
	public ArrayList<Tuple> tuples()
	{
		if(this.tuples == null)
		{
			this.tuples =  new ArrayList<Tuple>();
		}
		return this.tuples;
	}
	
}
