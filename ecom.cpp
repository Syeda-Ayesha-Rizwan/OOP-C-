/*E-commerce System.
Classes
• Product
Attributes: productName, productID, price.
Constructor to initialize the attributes.
Getter and setter methods.
• Customer
Attributes: customerName, customerID, cart (this should be a ShoppingCart object).
Constructor to initialize customerName and customerID. The cart should be initialized as a new
ShoppingCart object.
Getter and setter methods.
• Order
Attributes: orderID, products (a list of Product objects), totalAmount.
Constructor to initialize the orderID and products. Compute the totalAmount based on the products.
Getter and setter methods.
• ShoppingCart
Attributes: items (a list of Product objects).
Constructor that initializes items as an empty list.
Methods: addItem(Product product), removeItem(Product product), and checkout(). The checkout()
method should return an Order object created based on the items in the cart.
• Main Method
Create a main method where you:
Instantiate a few Product and Customer objects.
Add some products to a customer's shopping cart.
Have the customer checkout, creating an Order.
Quiz 1
1.75 Marks
Object Oriented Programming (CSC103)
 */
