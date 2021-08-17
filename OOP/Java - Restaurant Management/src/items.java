public class items{
	private int tableId;
	private String waiterName;
	private String itemName;
	private int itemCost;
	private int numberOfSold=0;
	private int orderNumber;
	
	public int getOrderNumber() {
		return orderNumber;
	}

	public void setOrderNumber(int orderNumber) {
		this.orderNumber = orderNumber;
	}

	public items(int tableId, String waiterName, String itemName, int itemCost) {
		super();
		this.tableId = tableId;
		this.waiterName = waiterName;
		this.itemName = itemName;
		this.itemCost = itemCost;
	}

	public void addMore(int i){
		numberOfSold= numberOfSold+1;
	}
	
	public int getTableId() {
		return tableId;
	}

	public void setTableId(int tableId) {
		this.tableId = tableId;
	}

	public String getWaiterName() {
		return waiterName;
	}

	public void setWaiterName(String waiterName) {
		this.waiterName = waiterName;
	}

	public String getItemName() {
		return itemName;
	}

	public void setItemName(String itemName) {
		this.itemName = itemName;
	}

	public int getItemCost() {
		return itemCost;
	}

	public void setItemCost(int itemCost) {
		this.itemCost = itemCost;
	}

	public int getNumberOfSold() {
		return numberOfSold;
	}

	public void setNumberOfSold(int numberOfSold) {
		this.numberOfSold = numberOfSold;
	}
	
	
	

	

	
	
	
	
	
	
	
	
	
}