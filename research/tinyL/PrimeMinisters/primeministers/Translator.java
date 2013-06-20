package primeministers;

import java.util.ArrayList;
import java.util.Calendar;

import javax.swing.JOptionPane;

/**
 * トランスレータ：総理大臣のCSVファイルをHTMLページへと変換するプログラム。
 */
public class Translator extends Object
{
	/**
	 * CSVに由来するテーブルを記憶するフィールド。 
	 */
	private Table inputTable;
	
	/**
	 * HTMLに由来するテーブルを記憶するフィールド。
	 */
	private Table outputTable;
	
	/**
	 * トランスレータのコンストラクタ。
	 */
	public Translator()
	{
		super();
		return;
	}

	/**
	 * 在位日数を計算して、それを文字列にして応答する。
	 */
	public String computeNumberOfDays(String periodString)
	{
		ArrayList<String> anArrayList = IO.splitString(periodString,"年月日〜");
		Calendar aCalendar = Calendar.getInstance();
		int year = Integer.parseInt(anArrayList.get(0));
		int month = Integer.parseInt(anArrayList.get(1)) - 1;
		int date = Integer.parseInt(anArrayList.get(2));
		aCalendar.set(year,month,date);
		long start = aCalendar.getTime().getTime();
		aCalendar = Calendar.getInstance();
		if(anArrayList.size() > 3)
		{
		year = Integer.parseInt(anArrayList.get(3));
		month = Integer.parseInt(anArrayList.get(4)) - 1;
		date = Integer.parseInt(anArrayList.get(5));
		aCalendar.set(year,month,date);
		}
		
		long end = aCalendar.getTime().getTime();
		long days = (end - start)/(1000*60*60*24) + 1;
		String aString = Long.toString(days);
		
		return aString;
	}
	
	/**
	 * サムネイル画像から画像へ飛ぶためのHTML文字列を作成して、それを応答する。
	 */
	public String computeNumberOfImage(String aString,Tuple aTuple/*,int no*/)
	{
		StringBuffer aBuffer = new StringBuffer();
		aBuffer.append("<a name=\"");
		aBuffer.append(aTuple.values().get(aTuple.attributes().indexOfNo()));
		aBuffer.append("\" href=\"");
		aBuffer.append(aTuple.values().get(aTuple.attributes().indexOfImage()));
		aBuffer.append("\"><img class=\"borderless\" src=\"");
		aBuffer.append(aTuple.values().get(aTuple.attributes().indexOfThumbnail()));
		aBuffer.append("\" width=\"25\" height=\"32\" alt=\"");
		aBuffer.append(IO.splitString(aString,"/").get(1));
		aBuffer.append("\"></a>");
	
		return aBuffer.toString();
	}
	/**
	 * 総理大臣のCSVファイルをHTMLページへ変換する。
	 */
	public void perform()
	{

		Downloader aDownloader = new Downloader();
		Table aTable = aDownloader.table();
		aTable = this.table(aTable);
		Writer aWriter = new Writer();
		aWriter.table(aTable);
		
		System.out.println(aTable);
		String aString = "総理大臣のCSVファイルからHTMLページへの変換を無事に完了しました。\n";
		JOptionPane.showMessageDialog(null, aString, "報告", JOptionPane.PLAIN_MESSAGE);
		return;
	}
	
	/**
	 * 総理大臣のCSVファイルを基にしたテーブルから、HTMLページを基にするテーブルに変換して、それを応答する。
	 */
	public Table table(Table aTable)
	{
		this.inputTable = aTable;
		this.outputTable = new Table();
		outputTable.attributes(new Attributes("output"));
		ArrayList<String> nameArrayList = new ArrayList<String>();
		ArrayList<String> anArrayList = inputTable.attributes().names();
		int index = 0;
		for(String aString : anArrayList)
		{
			if(inputTable.attributes().indexOfThumbnail() != index)
			{
				nameArrayList.add(aString);			
			}
			if(inputTable.attributes().indexOfPeriod() == index)
			{
				nameArrayList.add("在位日数");
			}
			index++;
		}
		this.outputTable.attributes().names(nameArrayList);
		for(Tuple aTuple : inputTable.tuples())
		{
			ArrayList<String> valueArrayList = new ArrayList<String>();
			index = 0;
			for(String aString : aTuple.values())
			{
				if(inputTable.attributes().indexOfThumbnail() != index)
				{
					if(inputTable.attributes().indexOfImage() == index)
					{
						valueArrayList.add(this.computeNumberOfImage(aString,aTuple));
					}
					else
					{
						valueArrayList.add(aString);			
					}
				}
				if(inputTable.attributes().indexOfPeriod() == index)
				{
					valueArrayList.add(computeNumberOfDays(aString));
				}
				index++;
			}
			Tuple theTuple = new Tuple(outputTable.attributes(),valueArrayList);
			outputTable.add(theTuple);
		}
		return this.outputTable;
	}
}
