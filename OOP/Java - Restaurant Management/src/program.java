import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.*;
import java.util.*;
import java.text.DecimalFormat;
public class program {
	 
	static DecimalFormat f= new DecimalFormat("0.000");
	
	
	public static void setup(){
		Map<String,employers> employerHmap = new LinkedHashMap<String,employers>();
		Map<String,data> dataHmap= new LinkedHashMap<String,data>();
		Map<String,waiters> waiterHmap = new LinkedHashMap<String,waiters>();
		Map<Integer,tables> tableHmap = new LinkedHashMap<Integer,tables>();
		Map<Integer,orders> orderHmap = new LinkedHashMap<Integer,orders>();
		Map<Integer,items> itemHmap= new LinkedHashMap<Integer,items>();
		
		int tableId=0;
		BufferedReader in = null;
		try {
		    in = new BufferedReader(new FileReader("setup.dat"));
		    String read = null;
		    while ((read = in.readLine()) != null) {
		        String[] splited = read.split("\\s+");
		        String[] part=splited[1].split(";",5);
		        if(splited[0].equals("add_item")){
		        	
		        	dataHmap.put(part[0], new data(part[0],Float.parseFloat(part[1]),Integer.parseInt(part[2])));
		        	
		        }
		        if (splited[0].equals("add_employer")){
		        	employerHmap.put(part[0], new employers(part[0],Float.parseFloat(part[1])));
		        	
		        }
		        if(splited[0].equals("add_waiter")){
		        	waiterHmap.put(part[0], new waiters(part[0],Float.parseFloat(part[1])));
		        	
		        	
		        }
		        
		    
		    }
		    
		} catch (IOException e) {
		    System.out.println("There was a problem: " + e);
		    e.printStackTrace();
		} finally {
		    try {
		        in.close();
		    } catch (Exception e) {
		    }
		}
		BufferedReader in1 = null;
				
				try {
					int orderNumber=0;
					int itemNumber=0;
					
					in1 = new BufferedReader(new FileReader("commands.dat"));
				    String read1 = null;
				    while ((read1 = in1.readLine()) != null) {
				    	//System.out.println("order Number:"+orderNumber);
				    	String[] splited = read1.split("\\s+");
				  
				        if(splited[0].equals("create_table")){
				        	String[] part=splited[1].split(";");
				        	
				        	if(employerHmap.containsKey(part[0])){
				        		if(tableId<=4){
				        			if(employerHmap.get(part[0]).getOpenedTable()<2){
				        				tableHmap.put(tableId, new tables(tableId,Integer.parseInt(part[1]),part[0]));
				        				
				        				tableId=tableId+1;
				        				int tableCount= employerHmap.get(part[0]).getOpenedTable();
				        				tableCount=tableCount+1;
				        				employerHmap.get(part[0]).setOpenedTable(tableCount); 
				        				System.out.println("***********************************");
				        				System.out.println("PROGRESSING COMMAND: create_table");
				        				System.out.println("A new table has successfully been added");
				        				
				        			}
				        			else{
				        				System.out.println("***********************************");
				        				System.out.println("PROGRESSING COMMAND: create_table");
				        				System.out.println(part[0]+" has already created ALLOWED_MAX_TABLES tables!");
				        			}
				        		}
				        		else{
				        			System.out.println("***********************************");
				        			System.out.println("PROGRESSING COMMAND: create_table");
				        			System.out.println("Not allowed to exceed max. number of tables, MAX_TABLES");
				        		}
				        	
				        	}
				        	else{
				        		System.out.println("***********************************");
				        		System.out.println("PROGRESSING COMMAND: create_table");
				        		System.out.println("There is no employer named "+part[0]);
				        	}
				        }
				        
				        if(splited[0].equals("new_order")){
				        	//part[0]= waiter name, part[1]= customer number, part3= pizza,1,coke,1
				        	
				        
				        	boolean check= false;
		        			boolean check1=false;
				        	String[] part=splited[1].split(";");
				        	String[] part2=part[2].split(":");
				        	
				        	List<String> part3= new ArrayList<String>();
				        	
				        	int counter=0;
				        	
				        	for(String item: part2){
				        		String[] temp=item.split("-");
				        		part3.add(temp[0]);
				        		part3.add(temp[1]);
				        	}
				        	if(waiterHmap.containsKey(part[0])){
				        		if(waiterHmap.get(part[0]).getServicedTable()<3){
				        			
				        			int id = 0;
				        			for(Integer key: tableHmap.keySet()){
				        				if(Integer.parseInt(part[1])<=tableHmap.get(key).getCapacity()){
				        					if(tableHmap.get(key).getStiuation().equals("Free")){
				        						if(!check1){
				        							check= true;
					        						id=key;
					        						check1= true;
				        						}
				        						
				        					}
				        				}
				        			}
				        			
				        			if(check==true){
				        				check=false;
				        				
				        				System.out.println("***********************************");
						        		System.out.println("PROGRESSING COMMAND: new_order");
						        		System.out.println("Table (=ID "+id+") has been taken into service");
						        		tableHmap.get(id).setWaiterName(part[0]);
						        		int z=waiterHmap.get(part[0]).getServicedTable();
				        				z=z+1;
				        				waiterHmap.get(part[0]).setServicedTable(z);
				        				int a=waiterHmap.get(part[0]).getTotalServicedTable();
				        				a=a+1;
				        				waiterHmap.get(part[0]).setTotalServicedTable(a);
				        				
				        				orderHmap.put(orderNumber,new orders(id,part[0],0));
				        				orderHmap.get(orderNumber).setOrderNumber(orderNumber);
				        				
						        		int i=0;
						        		for(counter=0;counter<part3.size();){
						        			for(i=0;i<Integer.parseInt(part3.get(counter+1));){
						        				i=i+1;
						        				if(i<10){
						        					if(dataHmap.containsKey(part3.get(counter))){
						        						if(dataHmap.get(part3.get(counter)).getItemCount()!=0){
									        				itemNumber++;
							        						System.out.println("Item "+dataHmap.get(part3.get(counter)).getItemName()+" added into order");
									        				int y=dataHmap.get(part3.get(counter)).getItemCount();
									        				y=y-1;
									        				dataHmap.get(part3.get(counter)).setItemCount(y);
									        				itemHmap.put(itemNumber, new items(id,part[0],part3.get(counter),Integer.parseInt(part3.get(counter+1))));
									        				itemHmap.get(itemNumber).setOrderNumber(orderNumber);
									        				tableHmap.get(id).setStiuation("Reserved");
									        				int x=tableHmap.get(id).getOrderNumber();
									        				x=x+1;
									        				tableHmap.get(id).setOrderNumber(x);
									        				
									        				
									        				
									        			
									        				
									        				
									        				
									        			}
									        			else{
									        				System.out.println("Sorry! No "+dataHmap.get(part3.get(counter)).getItemName()+" in the stock!");
									        				
									        				
									        			}
						        						
						        					}else{
						        						System.out.println("Unknown item "+part3.get(counter));
						        					}
						        				}
						        				else{
						        					System.out.println("Not allowed to exceed max no. of max item in a single order!");
						        				}
						        				
						        			}
						        			
						        			counter=counter+2;
						        			
						        		}
						        		orderNumber++;
				        				
				        				
				        			}
				        			else{
				        				System.out.println("***********************************");
						        		System.out.println("PROGRESSING COMMAND: new_order");
						        		System.out.println("There is no appropriate table for this order!");
						        		check=false;
				        				
				        			}
				        				
				        				
				        				
				        			
				        		}
				        		else{
				        			System.out.println("***********************************");
					        		System.out.println("PROGRESSING COMMAND: new_order");
				        			System.out.println(waiterHmap.get(part[0]).getServicedTable());
					        		System.out.println("Not allowed to service max. number of tables, MAX_TABLE_SERVICES");
				        		}
				        		
				        		
				        		
				        		
				        		
				        	}
				        	else{
				        		System.out.println("***********************************");
				        		System.out.println("PROGRESSING COMMAND: new_order");
				        		System.out.println("There is no waiter named "+ part[0]);
				        	}
				       
				        
				        
				        
				        }
				        
				        
				        
				        if(splited[0].equals("add_order")){
				        	System.out.println("***********************************");
			        		System.out.println("PROGRESSING COMMAND: add_order");
				        	//part[0]= waiter name, part[1]= tableId, part3= pizza,1,coke,1
				        	
				        	String[] part=splited[1].split(";");
				        	String[] part2=part[2].split(":");
				        	
				        	List<String> part3= new ArrayList<String>();
				        	
				        	int counter=0;
				        	for(String item: part2){
				        		String[] temp=item.split("-");
				        		part3.add(temp[0]);
				        		part3.add(temp[1]);
				        	}
				        	
				        	if(part[0].equals(tableHmap.get(Integer.parseInt(part[1])).getWaiterName()) && tableHmap.get(Integer.parseInt(part[1])).getStiuation().equals("Reserved")){
				        		
				        		if(tableHmap.get(Integer.parseInt(part[1])).getOrderNumber()<5){
				        			int i=0;
				        			int a=waiterHmap.get(part[0]).getTotalServicedTable();
			        				a=a+1;
			        				waiterHmap.get(part[0]).setTotalServicedTable(a);
			        				
			        				for(counter=0;counter<part3.size();){
				        			
				        				for(i=0;i<Integer.parseInt(part3.get(counter+1));){
				        					i=i+1;
				        					if(i<10){
				        						if(dataHmap.containsKey(part3.get(counter))){
				        							if(dataHmap.get(part3.get(counter)).getItemCount()!=0){
					        							
					        							itemNumber++;
					        							
					        							System.out.println("Item "+dataHmap.get(part3.get(counter)).getItemName()+" added into order");
								        				int y=dataHmap.get(part3.get(counter)).getItemCount();
								        				y=y-1;
								        				dataHmap.get(part3.get(counter)).setItemCount(y);
								        				itemHmap.put(itemNumber, new items(Integer.parseInt(part[1]),part[0],part3.get(counter),Integer.parseInt(part3.get(counter+1))));
								        				tableHmap.get(Integer.parseInt(part[1])).setOrderNumber(orderNumber);
								        				itemHmap.get(itemNumber).setOrderNumber(orderNumber);
								        				
								        				
										        		
					        							
					        							
					        							
					        						}
					        						else{
					        						
					        							System.out.println("Sorry! No "+dataHmap.get(part3.get(counter)).getItemName()+" in the stock!");
					        							
					        						}
				        							
				        						}
				        						else{
				        							System.out.println("Unknow item "+part3.get(counter));
				        							
				        						}
				        						
				        						
				        					
				        						
				        					}
				        					else{
				        					
				        						System.out.println("Not allowed to exceed max no. of max item in a single order!");
				        						
				        					}
				        					
				        					
				        				}
				        				
				        				counter=counter+2;
				        			}
			        				orderHmap.put(orderNumber, new orders(Integer.parseInt(part[1]),part[0]));
			        				orderHmap.get(orderNumber).setOrderNumber(orderNumber);
			        				orderNumber++;
				        			
				        			
				        			
				        		}
				        		else{
				        			
					        		System.out.println("Not allowed to exceed max number of orders!");
				        			
				        		}
				        		
				        		
				        	}
				        	else{
				        		
				        		System.out.println("This table is either not in service now or kemal cannot be assigned this table!");
				        	}
				        	
				        	
				        }
				        
				        
				        if(splited[0].equals("check_out")){
				        	//part[0] waiter name, part[1] tableId
				        	String[] part=splited[1].split(";");
				        	System.out.println("***********************************");
		        			System.out.println("PROGRESSING COMMAND: check_out");
		        			Map<String,Integer> temp= new LinkedHashMap<String,Integer>();
		        			Map<Integer,String> willDeleteHmap= new LinkedHashMap<Integer,String>();
		        			boolean check= false;
		        			for(String key1: waiterHmap.keySet()){
		        				
		        				if(key1.equals(part[0])){
		        					check=true;
		        					break;
		        				}		
		        			}
		        			if(check==true){
		        				if(tableHmap.get(Integer.parseInt(part[1])).getStiuation().equals("Reserved") && tableHmap.get(Integer.parseInt(part[1])).getWaiterName().equals(part[0]) ){
		        					//itemHmap removing and getting checkout items
		        					for(Integer key: itemHmap.keySet()){
		        						if(itemHmap.get(key).getTableId()== Integer.parseInt(part[1]) ){
		        							
		        							if(temp.containsKey(itemHmap.get(key).getItemName()) ){
		        								int constant =temp.get(itemHmap.get(key).getItemName());
		        								temp.remove(key);
		        								temp.put(itemHmap.get(key).getItemName(), constant+1);		        								
		        								willDeleteHmap.put(key,"a");		        								
		        							}else{
		        								temp.put(itemHmap.get(key).getItemName(),1);		     								
		        								willDeleteHmap.put(key,"a");		        								
		        							}		        									        							
		        						}
		        					}
		        					for(Integer key: willDeleteHmap.keySet()){
			        					itemHmap.remove(key);
			        				}
			        				willDeleteHmap.clear();
			        				
			        				//orderHmap removing
			        				for(Integer key: orderHmap.keySet()){
			        					if(orderHmap.get(key).getTableId()==Integer.parseInt(part[1]) ){
			        						willDeleteHmap.put(key, "a");
			        						
			        					}
			        				}
			        				for(Integer key:willDeleteHmap.keySet()){
			        					orderHmap.remove(key);
			        				}
			        				//get table stiuation free
			        				tableHmap.get(Integer.parseInt(part[1])).setStiuation("Free");
			        				//Dicrease waiter's capacity
			        				int x=waiterHmap.get(part[0]).getServicedTable();
		        					x=x-1;
		        					waiterHmap.get(part[0]).setServicedTable(x);
		        					//delete waiter on table
		        					tableHmap.get(Integer.parseInt(part[1])).setWaiterName("NULL");
		        					//printing checkout
		        					double result=0;
		        					
		        					for(String key: temp.keySet()){
		        						float a=dataHmap.get(key).getItemCost();
		        						int b= temp.get(key);
		        						
		        						result=a*b+result;
		        						
		        						System.out.println(key+":\t"+f.format(a)+" (x "+b+") "+f.format(a*b)+" $");
		        					}
		        						System.out.println("Total:\t"+f.format(result)+" $");
		        					
		        					
		        				}else{
		        					System.out.println("This table is either not in service now or "+part[0]+" cannot be assigned this table!");
		        					
		        				}
		        			
		        				
		        				
		        				
		        			}
		        			else{
		        				System.out.println("There is no waiter named "+part[0]);
		        				
		        			}
		        			
		        			
				        	
				        	
				        	
				        	
				        }
				        if(splited[0].equals("stock_status")){
				        	System.out.println("***********************************");
		        			System.out.println("PROGRESSING COMMAND: stock_status");
				        	for(String key: dataHmap.keySet()){
				        		System.out.println(key+ ":"+"\t"+dataHmap.get(key).getItemCount());
				        	}
				        	
				        }
				        if(splited[0].equals("get_table_status")){
				        	System.out.println("***********************************");
		        			System.out.println("PROGRESSING COMMAND: get_table_status");
		        			for(Integer key: tableHmap.keySet()){
		        				
		        				if(tableHmap.get(key).getStiuation().equals("Free")){
		        					System.out.println("Table "+key+": Free");
		        				}
		        				else{
		        					System.out.println("Table "+key+": Reservered ("+tableHmap.get(key).getWaiterName()+")");
		        				}
		        			}
				        	
				        }
				        if(splited[0].equals("get_order_status")){
				        	Map<Integer,Integer> temp= new LinkedHashMap<Integer,Integer>();	
				        	System.out.println("***********************************");
		        			System.out.println("PROGRESSING COMMAND: get_order_status");
				        	for(Integer key:tableHmap.keySet()){
				        		
				        		int x=0;
				        		
				        		for(Integer key1:orderHmap.keySet()){
				        			
				        			if(orderHmap.get(key1).getTableId()==key){
				        				
				        				x=x+1;
				        			}
				        			
				        				
				        			}
				        		temp.put(key, x);
				        		
				        		}
				        	for(Integer key:temp.keySet()){
				        		int i=0;
				        		System.out.println("Table: "+key);
				        		System.out.println("\t"+temp.get(key)+" order(s)");
				        		i=i+1;
				        	}
				        		
				        			
				        	
				        	
				        	
				        }
				        if(splited[0].equals("get_employer_salary")){
				        	System.out.println("***********************************");
		        			System.out.println("PROGRESSING COMMAND: get_employer_salary");
		        			for(String key : employerHmap.keySet()){
		        				System.out.println("Salary for "+key+": "+employerHmap.get(key).get_employer_salary());
		        				
		        			}
				        	
				        }
				        if(splited[0].equals("get_waiter_salary")){
				        	System.out.println("***********************************");
		        			System.out.println("PROGRESSING COMMAND: get_waiter_salary");
		        			for(String key: waiterHmap.keySet()){
		        				
		        				System.out.println("Salary for "+key+": "+waiterHmap.get(key).get_waiter_salary());
		        			}
				        	
				        }
				 
				        
				    
				}
				}catch (IOException e) {
				    
				    e.printStackTrace();
				} finally {
				    try {
				        in.close();
				    } catch (Exception e) {
				    }
				}
			}
	
	
	
	
	}
	