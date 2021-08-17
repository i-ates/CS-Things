public class  orders extends tables{
	private int totalCount;
	private int orderNumber;

	//constructor
	public orders(int tableId, String waiterName, int totalCount) {
		super(tableId, waiterName);
		this.totalCount = totalCount;
	}
	
	
	public int getOrderNumber() {
		return orderNumber;
	}


	public void setOrderNumber(int orderNumber) {
		this.orderNumber = orderNumber;
	}


	//getter-setter
	public int getTotalCount() {
		return totalCount;
	}


	


	public orders(int tableId, String waiterName) {
		super(tableId,waiterName);
		
	}


	public void setTotalCount(int totalCount) {
		this.totalCount = totalCount;
	}
	
	
	
}
