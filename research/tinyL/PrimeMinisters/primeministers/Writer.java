package primeministers;

import java.util.ArrayList;
import java.util.Calendar;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
/**
 * ライタ：総理大臣の情報のテーブルをHTMLページとして書き出す。
 */
public class Writer extends IO
{
	/**
	 * ライタのコンストラクタ。 
	 */
	public Writer()
	{
		super();
		return;
	}

	/**
	 * 属性リストを応答する。
	 */
	public Attributes attributes()
	{
		return this.table.attributes();
	}

	/**
	 * ローカルなHTMLのインデックスファイル(index.html)を応答するクラスメソッド。
	 */
	public File filenameOfHTML()
	{
		File aDirectory = Writer.directoryOfPages();
		File aFile = new File(aDirectory.getPath() + File.separator + "index.html");
		return aFile;
	}

	/**
	 * HTMLページを基にするテーブルを受け取って、インデックスファイル(index.html)に書き出す。
	 */
	public Table table(Table aTable)
	{
		this.table = aTable;
		try{
			FileOutputStream aFileOutputStream = new FileOutputStream(this.filenameOfHTML());
			OutputStreamWriter aOutputStreamWriter = new OutputStreamWriter(aFileOutputStream, IO.encodingSymbol());
			BufferedWriter outputWriter = new BufferedWriter(aOutputStreamWriter); 
			this.writeHeaderOn(outputWriter);
			this.writeTableBodyOn(outputWriter);
			this.writeFooterOn(outputWriter);
			outputWriter.close();
		}catch(FileNotFoundException anException){anException.printStackTrace();}
		catch(IOException anException){anException.printStackTrace();}
		return null;
	}

	/**
	 * タプル群を応答する。
	 */
	public ArrayList<Tuple> tuples()
	{
		return this.table.tuples();
	}

	/**
	 * 属性リストを書き出す。
	 */
	public void writeAttributesOn(BufferedWriter outputWriter)
	{
		ArrayList<String> anArrayList = this.attributes().names();
		for(String aString : anArrayList)
		{
			try {
				outputWriter.write(" <td class=\"center-pink\"><strong>" + aString + "</strong></td>");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try {
			outputWriter.write("</tr>");
		} catch (IOException e) {
			e.printStackTrace();
		}
		return;
	}

	private String addZero(int aNumber)
	{
		String aString = "";
		if(aNumber < 10)
		{
			aString = "0" + Integer.toString(aNumber);  
		}
		else{
			aString = Integer.toString(aNumber); 
		}
		return aString;
	}
	/**
	 * フッタを書き出す。
	 */
	public void writeFooterOn(BufferedWriter outputWriter)
	{
		Calendar cal1 = Calendar.getInstance();  

		int year = cal1.get(Calendar.YEAR);       
		int month = cal1.get(Calendar.MONTH) + 1;  
		int day = cal1.get(Calendar.DATE);         
		int hour = cal1.get(Calendar.HOUR_OF_DAY);
		int minute = cal1.get(Calendar.MINUTE);   
		int second = cal1.get(Calendar.SECOND);    

		try{
			outputWriter.write("<hr>\n");
			outputWriter.write("<div class=\"right-small\">Created by CSV2HTML4PrimeMinisters on "+ this.addZero(year) +"/"+ this.addZero(month) +"/"+ this.addZero(day) +" at "+ this.addZero(hour) + ":"+ this.addZero(minute) +":"+ this.addZero(second) +"</div>\n");
			outputWriter.write("</body>\n");
			outputWriter.write("</html>\n");
		}catch(IOException anException){anException.printStackTrace();}
		return;
	}

	/**
	 * ヘッダを書き出す。
	 */
	public void writeHeaderOn(BufferedWriter outputWriter)
	{
		try{
			outputWriter.write("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\n");
			outputWriter.write("<html lang=\"ja\">\n");
			outputWriter.write("<head>\n");
			outputWriter.write("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
			outputWriter.write("<meta http-equiv=\"Content-Style-Type\" content=\"text/css\">\n");
			outputWriter.write("<meta http-equiv=\"Content-Script-Type\" content=\"text/javascript\">\n");
			outputWriter.write("<meta name=\"description\" content=\"Prime Ministers\">\n");
			outputWriter.write("<meta name=\"author\" content=\"Suzuki Takamasa\">\n");
			outputWriter.write("<link rev=\"made\" href=\"mailto:g1044624@cc.kyoto-su.ac.jp\">\n");
			outputWriter.write("<link rel=\"index\" href=\"index.html\">\n");
			outputWriter.write("<style type=\"text/css\">\n");
			outputWriter.write("<!--\n");
			outputWriter.write("body {\n");
			outputWriter.write("    background-color : #ffffff;\n");
			outputWriter.write("    margin : 20px;\n");
			outputWriter.write("    padding : 10px;\n");
			outputWriter.write("    font-family : serif;\n");
			outputWriter.write("    font-size : 10pt;\n");
			outputWriter.write("}\n");
			outputWriter.write("a {\n");
			outputWriter.write("    text-decoration : underline;\n");
			outputWriter.write("    color : #000000;\n");
			outputWriter.write("}\n");
			outputWriter.write("a:link {\n");
			outputWriter.write("    background-color : #ffddbb;\n");
			outputWriter.write("}\n");
			outputWriter.write("a:visited {\n");
			outputWriter.write("    background-color : #ccffcc;\n");
			outputWriter.write("}\n");
			outputWriter.write("a:hover {\n");
			outputWriter.write("    background-color : #dddddd;\n");
			outputWriter.write("}\n");
			outputWriter.write("a:active {\n");
			outputWriter.write("    background-color : #dddddd;\n");
			outputWriter.write("}\n");
			outputWriter.write("div.belt {\n");
			outputWriter.write("    background-color : #eeeeee;\n");
			outputWriter.write("    padding : 0px 4px;\n");
			outputWriter.write("}\n");
			outputWriter.write("div.right-small {\n");
			outputWriter.write("    text-align : right;\n");
			outputWriter.write("    font-size : 8pt;\n");
			outputWriter.write("}\n");
			outputWriter.write("img.borderless {\n");
			outputWriter.write("    border-width : 0px;\n");
			outputWriter.write("    vertical-align : middle;\n");
			outputWriter.write("}\n");
			outputWriter.write("table.belt {\n");
			outputWriter.write("    border-style : solid;\n");
			outputWriter.write("    border-width : 0px;\n");
			outputWriter.write("    border-color : #000000;\n");
			outputWriter.write("    background-color : #ffffff;\n");
			outputWriter.write("    padding : 0px 0px;\n");
			outputWriter.write("    width : 100%;\n");
			outputWriter.write("}\n");
			outputWriter.write("table.content {\n");
			outputWriter.write("    border-style : solid;\n");
			outputWriter.write("    border-width : 0px;\n");
			outputWriter.write("    border-color : #000000;\n");
			outputWriter.write("    padding : 2px 2px;\n");
			outputWriter.write("}\n");
			outputWriter.write("td.center-blue {\n");
			outputWriter.write("    padding : 2px 2px;\n");
			outputWriter.write("    text-align : center;\n");
			outputWriter.write("    background-color : #ddeeff;\n");
			outputWriter.write("}\n");
			outputWriter.write("td.center-pink {\n");
			outputWriter.write("    padding : 2px 2px;\n");
			outputWriter.write("    text-align : center;\n");
			outputWriter.write("    background-color : #ffddee;\n");
			outputWriter.write("}\n");
			outputWriter.write("td.center-yellow {\n");
			outputWriter.write("    padding : 2px 2px;\n");
			outputWriter.write("    text-align : center;\n");
			outputWriter.write("    background-color : #ffffcc;\n");
			outputWriter.write("}\n");
			outputWriter.write("-->\n");
			outputWriter.write("</style>\n");
			outputWriter.write("<title>Prime Ministers</title>\n");
			outputWriter.write("</head>\n");
			outputWriter.write("<body>\n");
			outputWriter.write("<div class=\"belt\">\n");
			outputWriter.write("<h2>Prime Ministers</h2>\n");
			outputWriter.write("</div>");
		}catch(IOException anException){anException.printStackTrace();}
		return;
	}

	/**
	 * ボディを書き出す。
	 */
	public void writeTableBodyOn(BufferedWriter outputWriter)
	{

		try {
			outputWriter.write("<tbody>\n");
			outputWriter.write("<tr>\n");
			outputWriter.write("<td>\n");
			outputWriter.write("<table class=\"content\" summary=\"table\">\n");
			outputWriter.write("<tbody>\n");
			outputWriter.write("<tr>\n");
		} catch (IOException e) {
			e.printStackTrace();
		}
		this.writeAttributesOn(outputWriter);
		this.writeTuplesOn(outputWriter);

		try {
			outputWriter.write("</tbody>\n");
			outputWriter.write("</table>\n");
			outputWriter.write("</td>\n");
			outputWriter.write("</tr>\n");
			outputWriter.write("</tbody>\n");
			outputWriter.write("</table>\n");

		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

		return;
	}

	/**
	 * タプル群を書き出す。
	 */
	public void writeTuplesOn(BufferedWriter outputWriter)
	{
		int index = 0;
		ArrayList<Tuple> anArrayList = this.table().tuples();
		for(Tuple aTuple : anArrayList)
		{
			try {
				outputWriter.write("<tr>\n");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			ArrayList<String> valueArrayList = aTuple.values();
			for(String aString : valueArrayList)
			{
				if(index % 2 == 0 )
				{
					try {
						outputWriter.write("<td class=\"center-blue\">" + aString + "</td>\n");
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				else{
					try {
						outputWriter.write("<td class=\"center-yellow\">" + aString + "</td>\n");
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}		
			try {
				outputWriter.write("</tr>\n");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			index++;
		}
		return;
	}

}
