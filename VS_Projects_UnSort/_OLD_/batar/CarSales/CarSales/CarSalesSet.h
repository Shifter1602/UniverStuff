
// CarSalesSet.h: интерфейс класса CCarSalesSet
//


#pragma once

// создаваемый код 16 мая 2015 г., 11:27

class CCarSalesSetAccessor
{
public:
	TCHAR m_CarMark[256];
	TCHAR m_CarModel[256];
	TCHAR m_CarPrice[256];
	TCHAR m_DataOfSale[256];
	TCHAR m_SaleID[256];

	// Следующие создаваемые мастером члены данных содержат значения 
	// состояния для соответствующих полей в сопоставлении столбцов. 
	// Эти значение можно использовать для сохранения значений NULL, возвращаемых
	// базой данных, или для сохранения сведений об ошибках, когда компилятор 
	// возвращает ошибки. См. описание членов данных состояния полей в создаваемых 
	// мастером методах доступа в документации Visual C++ 
	// и сведения об использовании полей.
	// Примечание. Перед заданием или вставкой данных эти поля необходимо инициализировать!

	DBSTATUS m_dwCarMarkStatus;
	DBSTATUS m_dwCarModelStatus;
	DBSTATUS m_dwCarPriceStatus;
	DBSTATUS m_dwDataOfSaleStatus;
	DBSTATUS m_dwSaleIDStatus;

	// Следующие создаваемые мастером члены данных содержат значения 
	// длины для соответствующих полей в сопоставлении столбцов. 
	// Примечание. Для столбцов с переменной длиной значений необходимо
	//      инициализировать эти поля перед заданием или вставкой данных!

	DBLENGTH m_dwCarMarkLength;
	DBLENGTH m_dwCarModelLength;
	DBLENGTH m_dwCarPriceLength;
	DBLENGTH m_dwDataOfSaleLength;
	DBLENGTH m_dwSaleIDLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error Проблема безопасности: строка подключения может содержать пароль 
// Следующая строка подключения может содержать незашифрованные пароли или 
// другую конфиденциальную информацию. Удалите #error после просмотра строки подключения 
// в целях безопасности. Возможно, 
// потребуется сохранить пароль в другом виде или использовать другую проверку подлинности.
		hr = _db.OpenFromInitializationString(L"Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=D:\\Dima1\\CarSales\\CarSales.mdb;Mode=Share Deny None;Extended Properties=\"\";Jet OLEDB:System database=\"\";Jet OLEDB:Registry Path=\"\";Jet OLEDB:Database Password=\"\";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Password=\"\";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	BEGIN_COLUMN_MAP(CCarSalesSetAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_CarMark, m_dwCarMarkLength, m_dwCarMarkStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_CarModel, m_dwCarModelLength, m_dwCarModelStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_CarPrice, m_dwCarPriceLength, m_dwCarPriceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_DataOfSale, m_dwDataOfSaleLength, m_dwDataOfSaleStatus)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_SaleID, m_dwSaleIDLength, m_dwSaleIDStatus)
	END_COLUMN_MAP()
};

class CCarSalesSet : public CTable<CAccessor<CCarSalesSetAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, L"Sales", pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		CloseDataSource();
	}
};

