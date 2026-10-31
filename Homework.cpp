#include<iostream>
#include"MyVector.h"
#include<fstream>
#include<string>

using namespace std;

#pragma region Task
/*

## Geyim Mağazasının İdarəetmə Sistemi (Clothing Store)

### 1. OOP Prinsipləri
- `Product` adlı abstract class yaradın.
- `Clothing`, `Shoes` və `Accessories` class-larını `Product` class-ından törədin.
- Inheritance, Polymorphism, Encapsulation və Abstraction prinsiplərini tətbiq edin.
- Bütün field-lər private olmalıdır.
- Hər derived class-da `Display()` metodu override edilməlidir.

### 2. Vector və CRUD əməliyyatları
Bütün məhsulları `vector<Product*>` daxilində saxlayın.

Aşağıdakı əməliyyatları reallaşdırın:
1. Yeni məhsul əlavə etmək (Create).
2. Bütün məhsulları göstərmək (Read).
3. ID-yə görə məhsul axtarmaq.
4. Məhsulun qiymətini yeniləmək (Update).
5. ID-yə görə məhsulu silmək (Delete).

### 3. Exception Handling
Aşağıdakı halları yoxlayın və `try-catch` istifadə edin:
- Eyni ID ilə məhsul əlavə edilməsi.
- Mənfi və ya sıfır qiymət daxil edilməsi.
- Mövcud olmayan ID ilə əməliyyat aparılması.
- Boş məhsul adı daxil edilməsi.


### 4. File Stream
- Məhsulları `products.txt` faylında saxlayın.
- Proqram başladıqda məhsulları fayldan oxuyun.
- Məhsul əlavə edildikdə, yeniləndikdə və silindikdə faylı yeniləyin.
- `ifstream` və `ofstream` istifadə edin.


### 5. Proqram menyusu

1. Add Product
2. Show All Products
3. Search Product
4. Update Product Price
5. Delete Product
6. Save and Exit


### Tələblər
- Layihə fərdi şəkildə hazırlanmalıdır.
- Bütün əməliyyatlar düzgün işləməlidir.
- Dinamik yaddaş düzgün idarə olunmalıdır.
- Proqram bağlanıb yenidən açıldıqda məhsullar fayldan bərpa edilməlidir.

*/
#pragma endregion



class Product {
	string barcode;
	string name;
	string size;
	int baseCount;
	double sellingPrice;

public:
	Product(string barcode, string name, string size, int baseCount, double sellingPrice) {
		this->setBarcode(barcode);
		this->setName(name);
		this->setSize(size);
		this->setBaseCount(baseCount);
		this->setSellingPrice(sellingPrice);
	}


	string getBarcode() const {
		return barcode;
	}
	string getName() const {
		return name;
	}
	string getSize() const {
		return size;
	}
	int getBaseCount() const {
		return baseCount;
	}
	double getSellinPrice() const {
		return sellingPrice;
	}


	void setBarcode(string newBarcode) {
		if (newBarcode.empty())
		{
			throw string("Invalid barcode...");
		}
		this->barcode = newBarcode;
	}
	void setName(string newName) {
		if (newName.empty())
		{
			throw string("Invalid name....");
		}
		this->name = newName;
	}
	void setSize(string newSize) {
		if (newSize.length() < 1)
		{
			throw string("Invalid size....");
		}
		this->size = newSize;
	}
	void setBaseCount(int newBaseCount) {
		if (newBaseCount < 0)
		{
			throw string("Invalid BaseCount...");
		}
		this->baseCount = newBaseCount;
	}
	void setSellingPrice(double newSellingPrice) {
		if (newSellingPrice <= 0)
		{
			throw string("Invalid selling price...");
		}
		this->sellingPrice = newSellingPrice;
	}







	virtual void  Display() {
		cout << "Barcode: " << getBarcode() << endl;
		cout << "Product name: " << getName() << endl;
		cout << "Product size: " << getSize() << endl;
		cout << "Base count: " << getBaseCount() << endl;
		cout << "Selling price: " << getSellinPrice() << " AZN" << endl;
	}



	virtual ~Product() {};

};






class Clothing : public Product {
	string material;

public:
	Clothing(string material, string barcode, string name, string size, int baseCount, double sellingPrice)
		: Product(barcode, name, size, baseCount, sellingPrice) {
		this->setMaterial(material);
	}


	string getMaterial() const {
		return material;
	}
	void setMaterial(string newMaterial) {
		if (newMaterial.length() < 3)
		{
			throw string("Invalid material...");
		}
		this->material = newMaterial;
	}



	void Display() override {
		Product::Display();
		cout << "Clothing material: " << getMaterial() << endl;
	}
};





class Shoes : public Product {
	string category;

public:
	Shoes(string category, string barcode, string name, string size, int baseCount, double sellingPrice)
		: Product(barcode, name, size, baseCount, sellingPrice) {
		this->setCategory(category);
	}

	string getCategory() const {
		return category;
	}

	void setCategory(string newCategory) {
		if (newCategory.length() < 3)
		{
			throw string("Invalid category...");
		}
		this->category = newCategory;
	}




	void Display() override {
		Product::Display();
		cout << "Shoes category: " << getCategory() << endl;
	}

};





class Accessories : public Product {
	string type;

public:
	Accessories(string type, string barcode, string name, string size, int baseCount, double sellingPrice)
		: Product(barcode, name, size, baseCount, sellingPrice) {
		this->setType(type);
	}

	string getType() const {
		return type;
	}
	void setType(string newType) {
		if (newType.length() < 3)
		{
			throw string("Invalid type...");
		}
		this->type = newType;
	}





	void Display() override {
		Product::Display();
		cout << "Type Accessories: " << getType() << endl;
	}

};







class Butik {
	MyVector<Product*> products;

public:

	MyVector<Product*>& GetProducts()
	{
		return products;
	}

	// Yeni məhsul əlavə etmək (Create).
	void AddProduct(Product* newProduct) {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (products[i]->getBarcode() == newProduct->getBarcode())
			{
				throw string("Barcode already used...");
			}
		}
		products.push_back(newProduct);
	}



	//  Bütün məhsulları göstərmək (Read).
	void ShowAllProduct() {
		if (products.GetSize() == 0)
		{
			cout << "Product list is empty..." << endl;
			cout << endl;
			return;
		}
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			products[i]->Display();
			cout << endl;
		}
	}



	//  Barcode-a görə məhsul axtarmaq.
	void SearchProductBarcode(string barcode) {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (products[i]->getBarcode() == barcode)
			{
				products[i]->Display();
				return;
			}
		}
		throw string("Product not found...");
	}



	// indexe gore search etmek.
	int GetIndex(string barcode) {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (products[i]->getBarcode() == barcode)
			{

				return i;
			}
		}
		return -1;
	}



	// Məhsulun qiymətini yeniləmək (Update).
	void UpdatingProductPrice(string barcode, double newPrice) {
		int index = GetIndex(barcode);
		if (index == -1)
		{
			throw string("Product not found...");
		}
		products[index]->setSellingPrice(newPrice);
	}



	// Barcode-a görə məhsulu silmək (Delete).
	void Delete(string barcode) {
		int index = GetIndex(barcode);
		if (index == -1)
		{
			throw string("Product not found...");
		}
		delete products[index];
		products.pop_index(index);
	}




	// Destructor
	~Butik() {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			delete products[i];
		}
	}
};



void WriteToFile(MyVector<Product*>& product, string path = "butik.txt") {
	ofstream fs(path, ios::out);
	if (fs.is_open())
	{
		for (int i = 0; i < product.GetSize(); i++) {

			Product* p = product[i];

			Clothing* c = dynamic_cast<Clothing*>(p);
			if (c != nullptr)
			{
				fs << "Clothing#";
			}

			Shoes* s = dynamic_cast<Shoes*>(p);
			if (s != nullptr)
			{
				fs << "Shoes#";
			}

			Accessories* a = dynamic_cast<Accessories*>(p);
			if (a != nullptr)
			{
				fs << "Accessories#";
			}

			fs << p->getBarcode() << "#"
				<< p->getName() << "#"
				<< p->getSize() << "#"
				<< p->getBaseCount() << "#"
				<< p->getSellinPrice() << endl;

			if (c != nullptr)
			{
				fs << c->getMaterial();
			}
			else if (s != nullptr)
			{
				fs << s->getCategory();
			}
			else if (a != nullptr)
			{
				fs << a->getType();
			}
			fs << endl;
		}
	}
	else
	{
		throw string("File couldn`t open...");
	}
	fs.close();
}





void ReadFromFile(MyVector<Product*>& product, string path = "butik.txt") {
	ifstream fs(path);
	if (fs.is_open())
	{
		while (!fs.eof())     // tam olaraq file-in sonuna qeder getmeyini isteyirik.
		{
			string row;       // bir setrin sonuna qeder getmyini row deyiseninde saxlayacagiq
			getline(fs, row);
			int counter = 0;      // #-lerin sayidni bildiren saygacdir yeni fieldlerimizi birbirinden ayrimaga komek edir

			Product* p = nullptr;;

			string str_baseCount;
			string str_sellingPrice;
			string productType;
			string barcode;
			string name;
			string size;

			string productData;


			for (char character : row)       // goturduyu 1setirdeki her bir simvolun uzerinde tek-tek gezecek
			{
				if (character != '#' && counter == 0)
				{
					productType += character;
				}
				else if (character != '#' && counter == 1)
				{
					barcode += character;
				}
				else if (character != '#' && counter == 2)
				{
					name += character;
				}
				else if (character != '#' && counter == 3)
				{
					size += character;
				}
				else if (character != '#' && counter == 4)
				{
					str_baseCount += character;
				}
				else if (character != '#' && counter == 5)
				{
					str_sellingPrice += character;
				}
				else if (character != '#' && counter == 6)
				{
					productData += character;
				}
				else
				{
					counter++;
				}
			}


			int baseCount = stoi(str_baseCount);
			double sellingPrice = stod(str_sellingPrice);


			if (productType == "Clothing")
			{
				p = new Clothing(productData, barcode, name, size, baseCount, sellingPrice);
			}
			else if (productType == "Shoes")
			{
				p = new Shoes(productData, barcode, name, size, baseCount, sellingPrice);
			}
			else if (productType == "Accessories")
			{
				p = new Accessories(productData, barcode, name, size, baseCount, sellingPrice);
			}

			if (p != nullptr)
			{
				product.push_back(p);
			}
		}

	}
	else
	{
		throw string("File not found....");
	}
	fs.close();
}









void main() {

	Butik b;

	try
	{
		ReadFromFile(b.GetProducts());
	}
	catch (string error)
	{
		cout << error << endl;
	}


	int choice;
	do {
		cout << "1. Add Product" << endl;
		cout << "2. Show All Products" << endl;
		cout << "3. Search Product" << endl;
		cout << "4. Update Product Price" << endl;
		cout << "5. Delete Product" << endl;
		cout << "6. Save and Exit" << endl;
		cout << "Chosse:";
		cin >> choice;
		cout << endl;

		try
		{
			if (choice == 1)
			{
				int productChoice;
				cout << "1. Clothing" << endl;
				cout << "2. Shoes" << endl;
				cout << "3. Accessories" << endl;
				cout << "- Choose product type: ";
				cin >> productChoice;
				cout << endl;

				Product* p = nullptr;
				if (productChoice == 1)
				{
					p = new Clothing("Cotton", "12345678", "Black Jeans", "42", 12, 44);
				}
				else if (productChoice == 2)
				{
					p = new Shoes("Classic", "7788994455", "Loafer", "41", 9, 188);
				}
				else if (productChoice == 3)
				{
					p = new Accessories("Gold", "1011121314", "Bracelet", "18 Karat", 21, 2666);
				}

				b.AddProduct(p);
				WriteToFile(b.GetProducts());
			}
			else if (choice == 2)
			{
				b.ShowAllProduct();
			}
			else if (choice == 3)
			{
				string barcode;
				cout << "Enter barcode: ";
				cin >> barcode;
				b.SearchProductBarcode(barcode);
			}
			else if (choice == 4)
			{
				string barcode;
				double newPrice;

				cout << "Enter new barcode: ";
				cin >> barcode;

				cout << "Enter new price: ";
				cin >> newPrice;

				b.UpdatingProductPrice(barcode, newPrice);
				WriteToFile(b.GetProducts());
				cout << "Price updated successfully!" << endl;
			}
			else if (choice == 5)
			{
				string barcode;
				cout << "Enter deleting barcode: ";
				cin >> barcode;

				b.Delete(barcode);
				WriteToFile(b.GetProducts());
				cout << "Product deleted successfully!" << endl;
				cout << endl;
			}
		}
		catch (string error)
		{
			cout << "Error: " << error << endl;
		}

	} while (choice != 6);



}

