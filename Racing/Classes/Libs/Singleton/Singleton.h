#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>

class Singleton
{
public:
	static T* GetInstance()
	{
		if(!m_pInstance)
		{
			m_pInstance = new T();
		}

		return m_pInstance;
	}

private:
	static T* m_pInstance;
};

template <class T>
T* Singleton<T>::m_pInstance = nullptr;


#endif //SINGLETON_H