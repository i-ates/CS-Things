public class tables {
	private int tableId; 
	private int capacity;
	private String stiuation;
	private String waiterName;
	private String empoloyerName;
	private int orderNumber;
	
public tables(int tableId, int capacity, String empoloyerName) {
			this.tableId = tableId;
			this.capacity = capacity;
			this.stiuation = "Free";
			this.waiterName = "NULL";
			this.empoloyerName = empoloyerName;
}
		
	
//Getter-Setter
	
	public tables(int tableId, String waiterName) {
	this.tableId=tableId;
	this.waiterName=waiterName;
}


	public int getOrderNumber() {
		return orderNumber;
	}


	public void setOrderNumber(int orderNumber) {
		this.orderNumber = orderNumber;
	}


	public int getTableId() {
		return tableId;
	}
	public void setTableId(int tableId) {
		this.tableId = tableId;
	}
	public int getCapacity() {
		return capacity;
	}
	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}
	public String getStiuation() {
		return stiuation;
	}
	public void setStiuation(String stiuation) {
		this.stiuation = stiuation;
	}
	public String getWaiterName() {
		return waiterName;
	}
	public void setWaiterName(String waiterName) {
		this.waiterName = waiterName;
	}
	public String getEmpoloyerName() {
		return empoloyerName;
	}
	public void setEmpoloyerName(String empoloyerName) {
		this.empoloyerName = empoloyerName;
	}
}
