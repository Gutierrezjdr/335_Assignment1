// Include your name here.
// Place comments describing the class Chain (two lines).

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <sstream>
#include <string>



namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>

class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain() 
  {
   size_=0;
   array_=nullptr;
  }

  // Copy-constructor.
  Chain(const Chain &rhs)
  {
   size_=rhs.size_;
   array_=new Object[size_];
   for(unsigned int i=0;i<size_;++i) 
     array_[i]=rhs.array_[i];



  }	

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Chain copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Chain& operator=(const Chain &rhs) 
  {
    if(this!=&rhs)
    {
	 size_= rhs.size_;
	 for(unsigned int i=0;i<size_;i++)
		 array_[i]=rhs.array_[i];
     //*array_=*rhs.array_;
    }
	 
    return *this;
  }

  // Move-constructor. 
  Chain(Chain &&rhs) : size_{rhs.size()}, array_{rhs.array_}
  {
	for(unsigned int i=0;i<size_;++i)
	{
	 array_[i]=rhs.array_[i];
	}
    rhs.size_=0;
    rhs.array_=nullptr;
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Chain& operator=(Chain &&rhs) 
  {
    std::swap(array_,rhs.array_);
    std::swap(size_,rhs.size_);
	
	rhs.size_=0;
	rhs.array_=nullptr;
	
    return *this; 
  }

  ~Chain()
  {
   size_=0;
   delete [] array_;
  }

  // End of big-five.

  // One parameter constructor.
 explicit Chain(const Object& item )
  {
	size_=1;
    array_=new Object{item};
	
  }

  // Read a chain from standard input.
  void ReadChain()
  {
  
   
   std::string input;
   std::string sizeString;
   int start=0;
   
   std::getline(std::cin,input);
   
   for(unsigned int i=1;i<input.size();i++)
   {
	   
	   
	   if(input[i]==':')
	   {	   
		   start=i;
		   break;
	   }
	   else
		 sizeString+=input[i]; 
	   
   }

   std::stringstream sizeStream(sizeString);
   sizeStream>>size_;
  
   delete [] array_;
   
   array_=new Object[size_];
   Object element;
   
   std::stringstream ss(input.substr(start+2,input.size()-start-3)); 
   
   for(unsigned int i=0;i<size_;i++)
   {
	ss>>element;		  
	array_[i] = element;
   }
   
  }

  size_t size() const 
  { 
   return size_;
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const
  { 
   //abort if array size=0;
    // Write something
	if(location> size_)
		abort();
	
  return array_[location];
  }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location)
 { 
    if(location> size_)
		abort();
 //  array_[location]=new char{};
   return array_[location];
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2)
 {
    Chain c;
	c.size_=c1.size_+c2.size_;
	
	c.array_= new Object[c.size_];
	
	for(unsigned int i=0;i<c1.size_;i++)
	{
		
	  	c.array_[i]=c1.array_[i];
	}
	for(unsigned int i=0;i<c2.size_;i++)
	{
		
    	c.array_[c1.size_+i]=c2.array_[i];
	}
	return c;
 }
 friend Chain operator+(const Chain &c1, const Object add)
 {
    Chain c;
	
	c.size_=c1.size_;
	c.array_= new Object[c.size_+1];
	
	for(unsigned int i=0;i<c1.size_;i++)
	{
		
	  	c.array_[i]=c1.array_[i];
	}
    c.array_[c1.size_]= add;
	
	return c;
 }

 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) 
 {
	 
   out<<"[";
   for(unsigned int i=0;i<a_chain.size_;i++)
   {
	 if(i==a_chain.size_-1)
		 out<<a_chain.array_[i]; 
	 else
		 out<<a_chain.array_[i]<<" "; 
   }
    out<<"]"<<std::endl;
    return out;
	
 }
 
 private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
