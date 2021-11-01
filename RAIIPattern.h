#include <utility>

template <class T>
class FileReader
{
  private:
    using Source = typename T::ObjectType;
    T& object;
    Source& objType;
  public:
    FileReader(T& _dataAcces) 
     : object (_dataAcces),
       objType (_dataAcces.GetObjectType())
    {
        this->objType.OpenFile();  
    }

    Source* operator->()
    {
        return &objType;
    }

    ~FileReader()
    {
        this->objType.CloseFile();
    }

};

template <class T>
class DataAccess
{
 public:
   using ObjectType = T;

 private:
    T object;

 public:
    template <class... Argv>
    DataAccess(Argv&& ...argc)
     : object {std::forward<Argv>(argc)...}
    {
    }

    auto GetFileData()
    {
        return FileReader<DataAccess<T>>(*this);
    }

    auto& GetObjectType()
    {
        return object;
    }
};

