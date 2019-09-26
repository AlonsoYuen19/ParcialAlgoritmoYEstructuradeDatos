#pragma once
template <typename T>
class list
{
public:
	struct Node
	{
		T data;
		Node* anterior;
		Node* siguiente;
	};

	class iterator
	{
	private:
		Node* nodo;
	public:
		iterator(Node* node = nullptr)
		{
			nodo = node;
		}

		iterator operator ++(int)
		{
			iterator temp = nodo;
			nodo = nodo->siguiente;
			return temp;
		}
		iterator operator ++()
		{
			nodo = nodo->siguiente;
			return *this;
		}
		iterator operator --(int)
		{
			iterator temp = nodo;
			nodo = nodo->anterior;
			return *this;
		}

		iterator operator --()
		{
			nodo = nodo->anterior;
			return *this;
		}

		T& operator *()
		{
			return nodo->data;
		}

		bool operator !=(iterator& iter)
		{
			return nodo != iter.nodo;
		}

		bool operator ==(iterator& iter)
		{
			return nodo == iter.nodo;
		}

		Node* getNode()
		{
			return this->nodo;
		}
	};

public:
	list() :_iSize(0)
	{
		_Cabeza.data = 0;
		_Cabeza.anterior = nullptr;
		_Cabeza.siguiente = &_MiCola;
		_MiCola.data = 0;
		_MiCola.anterior = &_Cabeza;
		_MiCola.siguiente = nullptr;
	}

	~list()
	{
	}

	iterator begin()
	{
		iterator begin(_Cabeza.siguiente);
		return begin;
	}
	iterator end()
	{
		iterator end(&_MiCola);
		return end;
	}

	void push_front(T data)
	{
		Node* pNode = new Node;

		pNode->data = data;
		_iSize++;

		pNode->anterior = &_Cabeza;
		pNode->siguiente = _Cabeza.siguiente;
		pNode->anterior->siguiente = pNode;
		pNode->siguiente->anterior = pNode;
	}

	void push_back(T data)
	{
		Node* pNode = new Node;

		pNode->data = data;
		_iSize++;

		pNode->anterior = _MiCola.anterior;
		pNode->siguiente = &_MiCola;
		pNode->anterior->siguiente = pNode;
		pNode->siguiente->anterior = pNode;
	}
	void clear()
	{
		while (_iSize != 0)
			pop_front();
	}

	int size()
	{
		return _iSize;
	}
	bool empty()
	{
		if (_iSize == 0)
			return true;
		return false;
	}

	iterator erase(iterator iter)
	{
		iterator temp = iter;
		Node* pNode = temp.getNode();
		++temp;

		pNode->data = 0;
		pNode->siguiente->anterior = pNode->anterior;
		pNode->anterior->siguiente = pNode->siguiente;
		delete(pNode);

		return temp;
	}

private:
	int _iSize;
	Node _Cabeza;
	Node _MiCola;
};