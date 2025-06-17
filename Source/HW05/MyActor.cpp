// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = DefaultRoot;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	Move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move() {
	UE_LOG(LogTemp, Warning, TEXT("시작 좌표 (%.0f, %.0f, %.0f)"), Start.X, Start.Y, Start.Z);	

	for (int i = 0; i < 10; i++) { // 10회 반복
		UE_LOG(LogTemp, Warning, TEXT("[ %d 번째 이동 ]"), i + 1);
		CreateEvent();
		FVector prevPos = Start;

		Start = FVector(Start.X + Step(), Start.Y + Step(), Start.Z);

		UE_LOG(LogTemp, Warning, TEXT("현재 좌표 (%.0f, %.0f, %.0f)"), Start.X, Start.Y, Start.Z);
		UE_LOG(LogTemp, Warning, TEXT("이동 거리 %.1f"), Distance(prevPos, Start));
	}
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT("< < < < < 실행 완료 > > > > >"));
	UE_LOG(LogTemp, Warning, TEXT("총 이동 거리 : %.1f"), TotalDistance);
	UE_LOG(LogTemp, Warning, TEXT("총 이벤트 발생횟수 : %d"), EventCnt);
}

int32 AMyActor::Step() {
	int32 RandomValue = FMath::RandRange(0, 1); // 0혹은 1 랜덤 출력
	return RandomValue;
}

void AMyActor::CreateEvent(){
	if (FMath::RandRange(0, 1)) {
		UE_LOG(LogTemp, Warning, TEXT("* 이벤트 발생 *"));
		EventCnt++;
	}
}

float AMyActor::Distance(FVector prevPos, FVector nowPos){

	float dx = prevPos.X - nowPos.X;
	float dy = prevPos.Y - nowPos.Y;

	float distance = FMath::Sqrt(dx * dx + dy * dy);

	TotalDistance += distance;

	return distance;
}