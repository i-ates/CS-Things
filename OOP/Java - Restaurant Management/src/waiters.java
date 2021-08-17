public class waiters extends workers {
	private int servicedTable=0;
	private int totalServicedTable=0;
	
	
	

	//constructor
	public waiters(String name, float salary) {
		super(name, salary);
		
	}

	
	//getter-setter
	public int getServicedTable() {
		return servicedTable;
	}

	public void setServicedTable(int servicedTable) {
		this.servicedTable = servicedTable;
	}
	
	public int getTotalServicedTable() {
		return totalServicedTable;
	}


	public void setTotalServicedTable(int totalServicedTable) {
		this.totalServicedTable = totalServicedTable;
	}
	
	public double get_waiter_salary(){
		double result;
		float a=this.totalServicedTable;
		float b=getSalary();
		result=a*b*0.05+b;
		return result;
		
		
	}
}
