#include "pch.h"
using namespace System;
using namespace System::IO;
namespace lab17
{
	public ref class Program
	{
	public:
		static void Main()
		{
			//Вывод всех папок
			for each (String ^ entry in Directory::GetDirectories("C:\\Blend"))
			{
				DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry));
			}
			for each (String ^ entry in Directory::GetDirectories("C:\\Blend"))
			{
				for each (String ^ entry1 in Directory::GetDirectories((gcnew DirectoryInfo(entry))->FullName + "\\"))
				{
					DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry1));
				}
			}

			//Вывод атрибутов всех файлов
			for each (String ^ entry in Directory::GetFiles("C:\\Blend"))
			{
				DisplayFileSystemInfoAttributes(gcnew FileInfo(entry));
			}
			for each (String ^ entry in Directory::GetDirectories("C:\\Blend"))
			{
				for each (String ^ entry1 in Directory::GetFiles((gcnew DirectoryInfo(entry))->FullName + "\\"))
				{
					DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry1));
				}
			}
		}
		static void DisplayFileSystemInfoAttributes(FileSystemInfo^ fsi)
		{
			// Assume that this entry is a file.
			String^ entryType = "File";
			// Determine if entry is really a directory
			if ((fsi->Attributes & FileAttributes::Directory) == FileAttributes::Directory)
			{
				entryType = "Directory";
			}
			// Show this entry's type, name, and creation date.
			Console::WriteLine("{0} entry {1} was created on {2:D}", entryType, fsi->FullName, fsi->CreationTime);
		}
	};
};
int main()
{
	lab17::Program::Main();
}