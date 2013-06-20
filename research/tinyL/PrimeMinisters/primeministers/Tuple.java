package primeministers;

import java.util.ArrayList;
/**
 * タプル：総理大臣の情報テーブルの中の各々のレコード。
 */
public class Tuple extends Object
{
	/**
	 * 属性リストを記憶するフィールド。
	 */
	private Attributes attributes;
	
	/**
	 * 値リストを記憶するフィールド。
	 */
	private ArrayList<String> values;
	
	/**
	 * 属性リストと値リストからタプルを作るコンストラクタ。
	 */
	public Tuple(Attributes instanceOfAttributes, ArrayList<String> valueCollection)
	{
		super();
		this.attributes = instanceOfAttributes;
		this.values = valueCollection;
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
	 * 自分自身を文字列にして、それを応答する。
	 */
	public String toString()
	{
		StringBuffer aBuffer = new StringBuffer();
		for(String aString: values)
		{
			aBuffer.append(aString);
			aBuffer.append(",");
		}
		aBuffer.deleteCharAt(aBuffer.length() - 1);
		return aBuffer.toString();
	
	}
	
	/**
	 * 値リストを応答する。
	 */
	public ArrayList<String> values()
	{
		return this.values;
	}
	
}
