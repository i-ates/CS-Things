
public class employers extends workers{
	private int openedTable=0;

	//constructor
	public employers(String name, float salary) {
		super(name, salary);
	}

	
	//getter-setter
	public int getOpenedTable() {
		return openedTable;
	}

	public void setOpenedTable(int openedTable) {
		this.openedTable = openedTable;
	}
	public double get_employer_salary(){
		double result;
		float a= this.openedTable;
		float b=getSalary();
		result=b*a*0.1+b;
		return result;
		
		
	}
}
