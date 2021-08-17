public class data {
	private String itemName;
	private float itemCost;
	private int itemCount;
	
	
	//constructor
	public data(String itemName, float itemCost, int itemCount) {
		this.itemName = itemName;
		this.itemCost = itemCost;
		this.itemCount = itemCount;
	}
	
	
	//getter-setter
	public String getItemName() {
		return itemName;
	}
	public void setItemName(String itemName) {
		this.itemName = itemName;
	}
	public float getItemCost() {
		return itemCost;
	}
	public void setItemCost(int itemCost) {
		this.itemCost = itemCost;
	}
	public int getItemCount() {
		return itemCount;
	}
	public void setItemCount(int itemCount) {
		this.itemCount = itemCount;
	}
	
	
}
